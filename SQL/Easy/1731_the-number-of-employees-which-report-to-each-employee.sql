# Write your MySQL query statement below
-- SELECT DISTINCT(m.reports_to) AS employee_id,
--     (SELECT e.name FROM Employees e WHERE e.employee_id = m.reports_to) AS name,
--     COUNT(m.employee_id) AS reports_count, ROUND(AVG(m.age)) AS average_age
-- FROM Employees m
-- WHERE m.reports_to IS NOT NULL
-- GROUP BY m.reports_to
-- ORDER BY m.reports_to
-- ;

SELECT m.employee_id, m.name, COUNT(e.employee_id) AS reports_count, ROUND(AVG(e.age)) AS average_age
FROM Employees m
LEFT JOIN Employees e
ON m.employee_id = e.reports_to
GROUP BY m.employee_id, m.name
HAVING reports_count > 0
ORDER BY m.employee_id
;