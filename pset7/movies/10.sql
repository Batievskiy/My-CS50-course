/*
In 10.sql, write a SQL query to list the names of all people
who have directed a movie that received a rating of at least 9.0.
Your query should output a table with a single column
for the name of each person.
If a person directed more than one movie that received a rating
of at least 9.0, they should only appear in your results once.


This is detailed description for beginners in programing like me:

join all tables we needed with intersections
and select names with rating >= 9.0 from them

SELECT DISTINCT column `name`
FROM table `movies`
JOIN table `directors`
	ON column `id` in table `movies` on intersection with column `movie_id` in table `directors`
JOIN table `people`
	ON column `id` in table `people` on intersection with column `person_id` in table `directors`
JOIN table `ratings`
	ON column `movie_id` in table `ratings` on intersection with column `id` in table `movies`
WHERE rating >= 9.0;

---< Dumbest way is to write queries - in ONE line! >---

SELECT name FROM people WHERE id IN (SELECT DISTINCT directors.person_id FROM directors JOIN movies ON movies.id = directors.movie_id WHERE id IN (SELECT movie_id FROM ratings WHERE rating >= 9.0));

or

SELECT DISTINCT name FROM movies JOIN directors ON movies.id = directors.movie_id JOIN people ON people.id = directors.person_id JOIN ratings ON ratings.movie_id = movies.id WHERE rating >= 9.0;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT DISTINCT name
FROM movies
JOIN directors
	ON movies.id = directors.movie_id
JOIN people
	ON people.id = directors.person_id
JOIN ratings
	ON ratings.movie_id = movies.id
WHERE rating >= 9.0;

/* we also can do it anothe way (a bit faster)
SELECT name
FROM people
WHERE id IN (
    SELECT DISTINCT directors.person_id
    FROM directors
    JOIN movies
        ON movies.id = directors.movie_id
    WHERE id IN (
        SELECT movie_id
        FROM ratings
        WHERE rating >= 9.0));
*/