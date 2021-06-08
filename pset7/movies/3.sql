/*
In 3.sql, write a SQL query to list the titles of all movies
with a release date on or after 2018, in alphabetical order.
Your query should output a table with a single column
for the title of each movie.
Movies released in 2018 should be included, as should movies
with release dates in the future.

This is detailed description for beginners in programing like me:

SELECT column `title`
FROM table `movies`
WHERE column `year` >= 2018;
ORDER BY column `title` (default descending order from a to z)

---< Dumbest way is to write queries - in ONE line! >---

SELECT title FROM movies WHERE year >= 2018 ORDER BY title

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT title
FROM movies
WHERE year >= 2018
ORDER BY title;
