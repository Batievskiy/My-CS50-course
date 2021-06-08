/*
In 6.sql, write a SQL query to determine the average rating
of all movies released in 2012.
Your query should output a table with a single columnand a single row
(not including the header) containing the average rating.

This is detailed description for beginners in programing like me:

SELECT AVG(column `rating`)
(AVG - Returns the average value of an expression)
FROM database `ratings`
WHERE column `movie_id` IN (here we get info from database
SELECT column `id`
FROM database `movies`
WHERE column `year` = 2012);

---< Dumbest way is to write queries - in ONE line! >---

SELECT AVG(rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT AVG(rating)
FROM ratings
WHERE movie_id IN (
  SELECT id
  FROM movies
  WHERE year = 2012);

