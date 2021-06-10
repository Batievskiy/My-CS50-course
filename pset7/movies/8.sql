/*
In 8.sql, write a SQL query to list the names of all people
who starred in Toy Story.
Your query should output a table with a single column
for the name of each person.
You may assume that there is only one movie in the database
with the title Toy Story.

This is detailed description for beginners in programing like me:

SELECT column `name`
FROM table `movies`
JOIN in table `stars`
ON intersection of column `movie_id` in table `stars` and column `id` in table `movies`
JOIN in table `people`
ON intersection of column `id` in table `people` and column `person_id` in table `stars`
WHERE column `title` = "Toy Story";

---< Dumbest way is to write queries - in ONE line! >---

SELECT name FROM movies JOIN stars ON stars.movie_id == movies.id JOIN people ON people.id == stars.person_id WHERE title = "Toy Story";

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT name
FROM movies
JOIN stars
    ON stars.movie_id == movies.id
JOIN people
    ON people.id == stars.person_id
WHERE title = "Toy Story";

/* and we also can do it another way
SELECT name
FROM people
WHERE id IN (
  SELECT DISTINCT stars.person_id
  FROM stars
  JOIN movies
  	ON movies.id = stars.movie_id
  WHERE title = "Toy Story");
*/