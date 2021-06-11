/*
In 12.sql, write a SQL query to list the titles of all movies
in which both Johnny Depp and Helena Bonham Carter starred.
Your query should output a table with a single column
for the title of each movie.
You may assume that there is only one person
in the databasewith the name Johnny Depp.
You may assume that there is only one person
the database with the name Helena Bonham Carter.

This is detailed description for beginners in programing like me:

this a bit harder:

SELECT column `title`
FROM table `movies`
WHERE column `id` IN new table (
    SELECT column `movie_id`
    FROM table `stars`
    WHERE column `person_id` IN new table (
        SELECT column `id`
        FROM table `people`
        WHERE column `name` = "Johnny Depp")
    INTERSECT - compares the result sets of two queries and returns distinct rows that are output by both queries.
    SELECT column `movie_id`
    FROM table `stars`
    WHERE column `person_id` IN new table (
        SELECT column `id`
        FROM table `people`
        WHERE column `name` = "Helena Bonham Carter")
);

---< Dumbest way is to write queries - in ONE line! >---

// CODE HERE

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT title
FROM movies
WHERE id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id IN (
        SELECT id
        FROM people
        WHERE name = "Johnny Depp")
    INTERSECT
    SELECT movie_id
    FROM stars
    WHERE person_id IN (
        SELECT id
        FROM people
        WHERE name = "Helena Bonham Carter"));