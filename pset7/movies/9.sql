/*
In 9.sql, write a SQL query to list the names of all people
who starred in a movie released in 2004, ordered by birth year.
Your query should output a table with a single column
for the name of each person.
People with the same birth year may be listed in any order.
No need to worry about people who have no birth year listed,
so long as those who do have a birth year are listed in order.
If a person appeared in more than one movie in 2004,
they should only appear in your results once.

This is detailed description for beginners in programing like me:

SELECT DISTINCT column `name`
DISTINCT - with no repetitions
FROM table `movies`
JOIN table `stars`
    ON column `movie_id` in table `stars` on intersection with column `id` in table `movies`
JOIN table `people`
    ON column `id` in table `people` on intersection with column `person_id` in table `stars`
WHERE year = 2004
ORDER BY birth;

---< Dumbest way is to write queries - in ONE line! >---

SELECT DISTINCT name FROM movies JOIN stars ON stars.movie_id == movies.id JOIN people ON people.id == stars.person_id WHERE year = 2004 ORDER BY birth;

or

SELECT name FROM people WHERE id IN (SELECT DISTINCT stars.person_id FROM stars JOIN movies ON movies.id = stars.movie_id WHERE year = 2004) ORDER BY birth;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT DISTINCT name
FROM movies
JOIN stars
    ON stars.movie_id = movies.id
JOIN people
    ON people.id = stars.person_id
WHERE year = 2004
ORDER BY birth;

/* We can also do it another way
SELECT name
FROM people
WHERE id IN (
    SELECT DISTINCT stars.person_id
    FROM stars
    JOIN movies
        ON movies.id = stars.movie_id
    WHERE year = 2004)
ORDER BY birth;
*/