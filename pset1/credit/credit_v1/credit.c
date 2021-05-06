#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // declare credit card number
    long card_number;

    int counter = 0; // counter of digits in card_number
    long card_copy; // for calculations in loops
    int firsts; // for calculate sum of every first number
    int seconds; // for calculate sum of every other number
    int first_digit; // for store firsts digits
    int second_digit; // for store seconds digits
    int sum1 = 0; // sum of firsts digits
    int sum2 = 0; // sum of every other number
    int sum3 = 0; // final sum

    // ask user for card number (but no validation here because of CS50 checklist requirements - but that is stupid as for me)
    card_number = get_long("write card number: ");

    // count card number of digits
    card_copy = card_number;
    while (card_copy > 0)
    {
        card_copy /= 10;
        counter++;
    }

    // restore card number to card copy after previous loop
    card_copy = card_number;

    // calculate check sum
    while (card_copy > 0)
    {
        {
            firsts = card_copy % 10;
            card_copy /= 10;
        }

        // here we get sum of all firsts digits from end
        sum1 = sum1 + firsts;

        {
            seconds = card_copy % 10;
            card_copy /= 10;
        }

        // here we get sum of all seconds digits from end
        seconds *= 2;
        if (seconds > 9)
        {
            seconds = 1 + (seconds % 10);
        }

        sum2 = sum2 + seconds;
    }

    // here we get final sum
    sum3 = sum1 + sum2;

    // get last digit in sum3
    sum3 %= 10;

    // restore card number to card copy after previous loop
    card_copy = card_number;

    // define first digit of card number
    first_digit = 0;
    while (card_copy > 0)
    {
        first_digit = card_copy % 10;
        card_copy /= 10;
    }

    // restore card number to card copy after previous loop
    card_copy = card_number;

    // define second digit of card number
    second_digit = 0;
    while (card_copy > 9)
    {
        second_digit = card_copy % 10;
        card_copy /= 10;
    }

    // validate first digit 4 - VISA

    if (((counter == 13) || (counter == 16)) && (sum3 == 0) && (first_digit == 4))
    {
        printf("VISA\n");
    }
    // validate first digit 5, second digit 1,2,3,4,5 - mastercard
    else if ((counter == 16) && (sum3 == 0) && (first_digit == 5 && (second_digit >= 1 & second_digit <= 5)))
    {
        printf("MASTERCARD\n");
    }
    // validate first digit 3, second digit 4, 7 - AMEX
    else if ((counter == 15) && (sum3 == 0) && (first_digit == 3 && (second_digit == 4 || second_digit == 7)))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}