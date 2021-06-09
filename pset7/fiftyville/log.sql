-- Keep a log of any SQL queries you execute as you solve the mystery.

/*  Theft toop place on July 28
    Theft took place on Chanberlin Street

    Goal is to identify:
    1. name of the thief
    2. city where the thief ecsaped to
    3. who the thief's accomplice was
    who helped them escape town
*/

--< 1. let's look what `description` we have >---

/*
    in table `crime_scene_reports`
    on July 28 on Chanberlin Street
*/

SELECT description
FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND street = "Chamberlin Street";

/*
description:

    Theft of the CS50 duck took place at > 10:15am <
    at the Chamberlin Street courthouse.
    Interviews were conducted today with three witnesses
    who were present at the time — each of their > interview <
    transcripts mentions the > courthouse <.
*/

--< 2. let's look up all interview transcripts we have >--

/*
    in table `interviews`
    on July 28
    with `courthouse` keyword from description
*/

SELECT transcript
FROM interviews
WHERE month = 7
AND day = 28
AND transcript LIKE "%courthouse%";

/*
transcript_1:

    Sometime within > ten minutes < of the theft, I saw the thief
    get into a car in the > courthouse parking lot < and drive away.
    If you have security footage from the courthouse parking lot,
    you might want to > look for cars < that left the parking lot
    in that time frame.

    so: > check names who exited courthouse between 10:15 and 10:25

transcript_2:

    I don't know the thief's name, but it was someone I recognized.
    Earlier this morning, before I arrived at the courthouse,
    I was walking by the > ATM on Fifer Street < and saw the thief there
    withdrawing some money.

    so: > check ATM withdrawings on Fofer Street
        that matches names who exited courthouse between 10:15 and 10:25

transcript_3:

    As the thief was leaving the courthouse, they called someone
    who talked to them for > less than a minute <.
    In the > call <, I heard the thief say that they were planning
    to take the earliest > flight < out of Fiftyville > tomorrow <.
    The thief then asked the person on the other end of the phone
    to purchase the flight ticket.

    so: > check calls less than 1 minute
        > check flight at day July 29
        that matches names who exited courthouse between 10:15 and 10:25
*/

--< 3. let's look up names of car owners who exited from courthouse >--
/*
    search for license_plate and names
    of cars exited between 10:15 and 10:25
    day July 28
    that intersects in column `license_plate`
    in tables `courthouse_security_logs`
    and column `license_plate` in table `people`
*/

SELECT name
FROM people
JOIN courthouse_security_logs
    ON courthouse_security_logs.license_plate = people.license_plate
WHERE month = 7
AND day = 28
and activity = "exit"
AND hour = 10
AND minute >= 15
AND minute <= 25;

/*  names found:

    Patrick
    Ernest
    Amber
    Danielle
    Roger
    Elizabeth
    Russell
    Evelyn
*/


--< 4. let's look up `atm_transaction` that matches this names >--
/*
    check name in table `people`
    whose `id` intersects with column person_id in table `bank_account`
    and check whose `account_number`
    intercests in column `account_number` in table `atm_transactions`
    with column `account_number` in table `bank_account`
    who withdraw money
    on Fifer Street
    day July 28
*/

SELECT DISTINCT name
FROM people
    JOIN bank_accounts
        ON bank_accounts.person_id = people.id
    JOIN atm_transactions
        ON  atm_transactions.account_number = bank_accounts.account_number
WHERE transaction_type = "withdraw"
AND atm_location = "Fifer Street"
AND day = 28
AND month = 7;

/* compare with previous result:

    1:              2:
    Patrick         <Danielle>-- MATCH
    <Ernest>        Bobby
    Amber           Madison
    <Danielle>      <Ernest>-- MATCH
    Roger           Roy
    <Elizabeth>     <Elizabeth>-- MATCH
    <Russell>       Victoria
    Evelyn          <Russell>-- MATCH

MATCHED names:

    Danielle
    Ernest
    Elizabeth
    Russell
*/

--< 5. Check names who called >--
/*
    find intersections in column `callers` from table `phone_calls`
    with columns `phone_number` from table `people`
    less than 1 minute (60 seconds)
    at day July 28
*/

SELECT name
FROM people
    JOIN phone_calls
        ON phone_calls.caller = people.phone_number
WHERE duration < 60
AND day = 28
AND month = 7;

/* compare with previous matched names:

    Danielle        Roger
    <Ernest>        Evelyn
    Elizabeth       <Ernest>-- MATCH
    <Russell>       Evelyn
                    Madison
                    <Russell>-- MATCH
                    Kimberly
                    Bobby
                    Victoria

MATCHED names:

    Ernest
    Russell

Almost found :) Nice!
*/

--< 6. let's check passengers on a flight >--
/*
    find names, seats, hour and flight IDs of passenger who
    has intersections in column `passport_number` from table `passengers`
    with column `passport_number` from table `people`
    and has intersections in column `id` from table `flights`
    with column `flight_id` from table `passengers`
    day July 29
    check first flight (6-8am)

*/

SELECT people.passport_number, name, seat, flight_id, hour
FROM people
    JOIN passengers
        ON passengers.passport_number = people.passport_number
    JOIN flights
        ON flights.id = passengers.flight_id
WHERE day = 29
AND month = 7
AND hour <= 8
ORDER BY hour, minute;

/* names found:

let's check our previous matched names:

    Ernest
    Russell

passport_number     name     | seat | flight_id | hour
7214083635          Doris    |  2A  |       36  |   8
1695452385          Roger    |  3B  |       36  |   8
5773159633          <Ernest> |  4A  |       36  |   8 >-- MATCH
1540955065          Edward   |  5C  |       36  |   8
8294398571          Evelyn   |  6C  |       36  |   8
1988161715          Madison  |  6D  |       36  |   8
9878712108          Bobby    |  7A  |       36  |   8
8496433585          Danielle |  7B  |       36  |   8

so: --> Ernest is the THIEF <--

*/

--< 7. let's check flight destination >--
/*
    name:               Ernest
    passport_number:    5773159633 >-- precise double check that he is on this flight
    flight id:          36 >-- easiest way to find a flight
    seat:               4A
    day:                July 29
*/

SELECT city, passport_number
FROM airports
    JOIN flights
        ON flights.destination_airport_id = airports.id
    JOIN passengers
        ON flights.id = passengers.flight_id
WHERE flight_id = 36
AND passport_number = 5773159633;

/* we also can do it another way just using flight_id:
SELECT city
FROM airports
WHERE id IN (
    SELECT destination_airport_id
    FROM flights
    WHERE id IN (
        SELECT flight_id
        FROM passengers
        WHERE flight_id = 36));

        /* you can also add this info but its excessive
        AND passport_number = 5773159633
        AND day = 29
        AND month = 7
        AND seat = "4A"));
        */

--< 8. let's find out who helped him (accomplice) >--
/*
    caller name:    "Ernest"
    duration:       less than 60 seconds
    day:            July 29
*/

SELECT name
FROM people
    JOIN phone_calls
        ON phone_calls.receiver = people.phone_number
WHERE day = 28
AND month = 7
AND duration < 60
AND caller = (
    SELECT phone_number
    FROM people
    WHERE name = "Ernest");

/* accomplice name found:

so: --> Berthold is an ACCOMPLICE <--

*/