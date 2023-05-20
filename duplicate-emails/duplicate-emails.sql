# Write your MySQL query statement below
SELECT Person.email AS Email
FROM Person
GROUP BY Email
HAVING Count(Email) > 1