/*
In 7.sql, write a SQL query that returns
the average energy of songs that are by Drake.
Your query should output a table with a single column
and a single row containing the average energy.
You should not make any assumptions about
what Drake’s artist_id is.

This is detailed description for beginners in programing like me:

SELECT AVG(column `energy`)
AVG - Returns the average value of an expression
FROM table `songs`
WHERE column `artist_id` = (
here we taking info from another table
SELECT column `id`
FROM table `artists`
WHERE column `name` == "Drake"
);

---< Dumbest way is to write queries - in ONE line! >---

SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name == "Drake");

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT AVG(energy)
FROM songs
WHERE artist_id = (
    SELECT id
    FROM artists
    WHERE name == "Drake");