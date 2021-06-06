/*
In 4.sql, write a SQL query that lists the names of any songs
that have danceability, energy, and valence greater than 0.75.
Your query should output a table with a single column
for the name of each song.

This is detailed description for beginners in programing like me:

SELECT column `name`
FROM table `songs`
WHERE (
column `danceability` > 0.75
AND column `energy` > 0.75
AND column `valence` > 0.75)
AND - Only includes rows where both conditions is true

---< Dumbest way is to write queries - in ONE line! >---

SELECT name FROM songs WHERE (danceability > 0.75 AND energy > 0.75 AND valence > 0.75);

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT name
FROM songs
WHERE (danceability > 0.75
    AND energy > 0.75
    AND valence > 0.75);