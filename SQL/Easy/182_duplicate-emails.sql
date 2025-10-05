# Write your MySQL query statement below

-- SELECT p.email AS Email
-- FROM Person p
-- GROUP BY p.email
-- HAVING COUNT(*)>1;

SELECT DISTINCT p.email
FROM Person p
INNER JOIN Person q
ON p.id <> q.id
AND p.email = q.email;