# Write your MySQL query statement below
SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS salary
FROM (
    SELECT
        departmentId,
        id,
        name,
        salary,
        DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee
    ORDER BY departmentId
) e
LEFT JOIN Department d
ON e.departmentId = d.id
WHERE e.rnk<4
;