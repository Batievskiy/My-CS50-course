/*
In 7.sql, write a SQL query to list all movies released in 2010
and their ratings, in descending order by rating.
For movies with the same rating, order them alphabetically by title.
Your query should output a table with two columns,
one for the title of each movie and one for the rating of each movie.
Movies that do not have ratings should not be included in the result.

This is detailed description for beginners in programing like me:

SELECT column `title`, column `rating`
FROM table `movies`
JOIN table `ratings` ON ratings.movie_id = movies.id
(take title column of table `movies` and
JOIN with column `rating` of table `ratings`
where both tables are have same id's)
WHERE column `year` = 2010;

---< Dumbest way is to write queries - in ONE line! >---

SELECT title, rating FROM movies JOIN ratings ON ratings.movie_id = movies.id ORDER BY rating DESC, title;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT title, rating
FROM movies
JOIN ratings ON ratings.movie_id = movies.id
WHERE year = 2010
ORDER BY rating DESC, title;
