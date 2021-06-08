/*
In 2.sql, write a SQL query to determine the birth year of Emma Stone.
Your query should output a table with a single column
and a single row (not including the header)
containing Emma Stone’s birth year.
You may assume that there is only one person in the database
with the name Emma Stone.

This is detailed description for beginners in programing like me:

SELECT column `birth`
FROM table `people`
WHERE column `name` LIKE "Emma Stone";
LIKE - Searches for a specified pattern in a column

---< Dumbest way is to write queries - in ONE line! >---

SELECT birth FROM people WHERE name LIKE "Emma Stone";

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT birth
FROM people
WHERE name LIKE "Emma Stone";