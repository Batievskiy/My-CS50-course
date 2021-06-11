/*
In 13.sql, write a SQL query to list the names of all people
who starred in a movie in which Kevin Bacon also starred.
Your query should output a table with a single column
for the name of each person.
There may be multiple people named Kevin Bacon in the database.
Be sure to only select the Kevin Bacon born in 1958.
Kevin Bacon himself should not be included in the resulting list.

This is detailed description for beginners in programing like me:

this is a bit tricky:
SELECT column `name`
FROM table `people`
WHERE name != "Kevin Bacon" (just exclude his name from resulting table)
AND column `id` IN new table from (
    SELECT column `person_id`
    FROM from table `stars`
    WHERE column `movie_id` IN new table from (
        SELECT column `movie_id`
        FROM table `stars`
        WHERE column `person_id` IN new table from (
            SELECT column `id`
            FROM table `people`
            WHERE column `name` = "Kevin Bacon"
            AND column `birth` = 1958)));

Actrually! Better to practice such nested queries from BOTTOM to TOP
Way easier to understand logic:

> we filter all `id`s from table `people` >---
we take all `id`s
from table `people`
where column `name` = "Kevin Bacon"
and column `birth` = 1958

> then we find filter all `movie_id`s >---
from table `stars`
where column `person_id` matches column `id` from previous filter result

> then we filter all `person_id`
from table `stars`
where column `person_id` matches column `person_id` from previous filter result

> then we filter all `names`
from table `people`
where column `id` matches column `person_id` from previous filter resuld

> and exclude "Kevin Bacon"s name from table's result

I hope thats clear some logic of such queries

---< I'm actually don't get all ways to use SQL >---
but at least some knowledges is gonna stay with me here :)

---< Dumbest way is to write queries - in ONE line! >---

SELECT name FROM people WHERE name != "Kevin Bacon" AND id IN (SELECT person_id FROM stars WHERE movie_id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958)));

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT name
FROM people
WHERE name != "Kevin Bacon"
AND id IN (
    SELECT person_id
    FROM stars
    WHERE movie_id IN (
        SELECT movie_id
        FROM stars
        WHERE person_id IN (
            SELECT id
            FROM people
            WHERE name = "Kevin Bacon"
            AND birth = 1958)));