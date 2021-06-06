/*
In 3.sql, write a SQL query to list the names
of the top 5 longest songs, in descending order of length.
Your query should output a table with a single column
for the name of each song.

This is detailed description for beginners in programing like me:

SELECT column `name`
FROM table `songs`
ORDER BY - Sorts the result set in ascending(ASC) or descending(DESC) order
by column `duration_ms` DESC
LIMIT - Specifies the number of records to return in the result set
limits output to only 5 rows

---< Dumbest way is to write queries - in ONE line! >---

SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT name
FROM songs
ORDER BY duration_ms DESC
LIMIT 5;