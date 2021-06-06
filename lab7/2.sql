/*
In 2.sql, write a SQL query to list the names
of all songs in increasing order of tempo.
Your query should output a table with a single column
for the name of each song.

This is detailed description for beginners in programing like me:

SELECT column `name`
FROM database `songs` and
ORDER BY - Sorts the result set in ascending(ASC) or descending(DESC) order
by column `tempo` in ASC - ascending order

---< Dumbest way is to write queries - in ONE line! >---

SELECT name FROM songs ORDER BY tempo ASC;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT name
FROM songs
ORDER BY tempo ASC;