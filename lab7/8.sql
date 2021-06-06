/*
In 8.sql, write a SQL query that lists the names of the songs
that feature other artists.
Songs that feature other artists will include “feat.”
in the name of the song.
Your query should output a table with a single column
for the name of each song.

This is detailed description for beginners in programing like me:

SELECT column `name`
FROM table `songs`
WHERE column `name`
LIKE "%feat.%"
LIKE - Searches for a specified pattern in a column
% - Represents zero, one, or multiple characters
_ - Represents a single character (MS Access uses a question mark (?) instead)

---< Dumbest way is to write queries - in ONE line! >---

SELECT name FROM songs WHERE name LIKE "%feat.%";

That's OK if line is short, BUT if they are not?

Best practices here:
https://www.geeksforgeeks.org/what-are-the-best-ways-to-write-a-sql-query/

Do not forget to close your command with a semicolon ;
*/

SELECT name
FROM songs
WHERE name LIKE "%feat.%";