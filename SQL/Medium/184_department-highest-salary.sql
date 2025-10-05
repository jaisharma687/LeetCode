# Write your MySQL query statement below
SELECT
    d.name AS Department,
    ed.name AS Employee,
    ed.salary AS Salary
FROM Department d
RIGHT JOIN (
    SELECT 
        e.departmentId, 
        e.name, 
        e.salary, 
        RANK() OVER (
            PARTITION BY e.departmentId 
            ORDER BY e.salary DESC
        ) AS salary_rank
    FROM Employee e
) ed
ON ed.departmentId = d.id
WHERE ed.salary_rank = 1
;