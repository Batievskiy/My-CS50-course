/*
In 11.sql, write a SQL query to list the titles of the five
highest rated movies (in order) that Chadwick Boseman starred in,
starting with the highest rated.
Your query should output a table with a single column
for the title of each movie.
You may assume that there is only one person in the database
with the name Chadwick Boseman.

This is detailed description for beginners in programing like me:

SELECT column `title`
FROM table `movies`
JOIN table `ratings` ON column `id` in table `movies` on intersection with column `movie_id` in table `ratings`
WHERE column `id`` IN table made from (
    SELECT column `movie_id` in table `stars`
    FROM table stars`
    WHERE columm `person_id` IN table made from (
        SELECT column `id`
        FROM table `people`
        WHERE column `name`
        LIKE "Chadwick Boseman"))
ORDER BY column `rating` in DESC (descending order)
LIMIT 5 (show olny 5 rows)

---< Dumbest way is to write queries - in ONE line! >---

SELECT title FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE id IN (SELECT stars.movie_id FROM stars WHERE person_id IN(SELECT id FROM people WHERE name LIKE "Chadwick Boseman")) ORDER BY rating DESC LIMIT 5;

or

SELECT title FROM movies JOIN stars ON stars.person_id = people.id JOIN people ON movies.id = stars.movie_id JOIN ratings ON ratings.movie_id = movies.id WHERE name = "Chadwick Boseman" ORDER BY rating DESC LIMIT 5;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT title
FROM movies
JOIN ratings
    ON movies.id = ratings.movie_id
WHERE id IN (
    SELECT stars.movie_id
    FROM stars
    WHERE person_id IN(
        SELECT id
        FROM people
        WHERE name
        LIKE "Chadwick Boseman"))
ORDER BY rating DESC
LIMIT 5;

/* we also can do it anothe way (bit slower)
join all tables we needed with intersections
and select title where name = "Chadwick Boseman"

SELECT title
FROM movies
JOIN stars ON stars.person_id = people.id
JOIN people ON movies.id = stars.movie_id
JOIN ratings ON ratings.movie_id = movies.id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;
*/

