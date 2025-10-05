# Write your MySQL query statement below
SELECT 
    f.name
FROM Employee f
WHERE f.id IN (
    SELECT
        e.managerId
    FROM Employee e
    GROUP BY e.managerId
    HAVING COUNT(e.managerId) >= 5
)
;