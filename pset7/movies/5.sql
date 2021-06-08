/*
In 5.sql, write a SQL query to list the titles and release years
of all Harry Potter movies, in chronological order.
Your query should output a table with two columns, one for the title
of each movie and one for the release year of each movie.
You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.

This is detailed description for beginners in programing like me:

SELECT columns `title` and `year`
FROM dtabase `movies`
WHERE column `title`
LIKE "Harry Potter%" (% - cuts off all characters after)
(LIKE - Searches for a specified pattern in a column)
ORDER BY column `year`
(ORDER BY - Sorts the result set in ascending or descending order)

---< Dumbest way is to write queries - in ONE line! >---

SELECT title FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT title, year
FROM movies
WHERE title
LIKE "Harry Potter%"
ORDER BY year;