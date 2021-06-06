/*
In 5.sql, write a SQL query that returns
the average energy of all the songs.
Your query should output a table with a single column
and a single row containing the average energy.

This is detailed description for beginners in programing like me:

SELECT AVG(column `energy`)
AVG - Returns the average value of an expression
FROM table `songs`

---< Dumbest way is to write queries - in ONE line! >---

SELECT AVG(energy) FROM songs;

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT AVG(energy)
FROM songs;