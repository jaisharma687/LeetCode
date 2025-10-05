# Write your MySQL query statement below
-- SELECT DISTINCT class
-- FROM (
--     SELECT class, COUNT(*) OVER (
--         PARTITION BY class
--     ) AS class_count
--     FROM Courses
-- ) c
-- WHERE class_count >= 5
-- ;

SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5
;