# Write your MySQL query statement below
SELECT e.employee_id, 
    CASE 
        WHEN COUNT(e.primary_flag) = 1 THEN e.department_id
        ELSE (
            SELECT f.department_id 
            FROM Employee f 
            WHERE e.employee_id = f.employee_id 
            AND f.primary_flag = 'Y'
        )
    END
    AS department_id
FROM Employee e
GROUP BY e.employee_id
;