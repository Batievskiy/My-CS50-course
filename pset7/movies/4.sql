/*
n 4.sql, write a SQL query to determine the number of movies
with an IMDb rating of 10.0.
Your query should output a table with a single column
and a single row (not including the header)
containing the number of movies with a 10.0 rating.

This is detailed description for beginners in programing like me:

SELECT COUNT(column `rating`)
FROM database `ratings`
WHERE column `rating` = 10.0;
COUNT - Returns the number of records returned by a select query

---< Dumbest way is to write queries - in ONE line! >---

SELECT COUNT(rating) FROM ratings WHERE rating = 10.0;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT COUNT(rating)
FROM ratings
WHERE rating = 10.0;