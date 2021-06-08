/*
In 1.sql, write a SQL query to list the titles
of all movies released in 2008.
Your query should output a table with a single column
for the title of each movie.

This is detailed description for beginners in programing like me:

SELECT column `title`
FROM table `movies`
WHERE column `year` = 2008;

---< Dumbest way is to write queries - in ONE line! >---

SELECT title FROM movies WHERE year = 2008;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT title
FROM movies
WHERE year = 2008;