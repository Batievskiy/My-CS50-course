/*
In 6.sql, write a SQL query that lists
the names of songs that are by Post Malone.
Your query should output a table with a single column
for the name of each song.
You should not make any assumptions about
what Post Malone’s artist_id is.

This is detailed description for beginners in programing like me:

SELECT column `name`
FROM table `songs`
WHERE column `artist_id` = (
here we taking info from another table
SELECT column `id`
FROM table `artists`
WHERE column `name` == "Post Malone"
);

---< Dumbest way is to write queries - in ONE line! >---

SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name == "Post Malone");

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT name
FROM songs
WHERE artist_id = (
    SELECT id
    FROM artists
    WHERE name == "Post Malone");