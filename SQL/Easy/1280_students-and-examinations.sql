# Write your MySQL query statement below
-- SELECT s.student_id, s.student_name, b.subject_name, COUNT(e.student_id) AS attended_exams
-- FROM Students s
-- CROSS JOIN Subjects b
-- LEFT JOIN Examinations e
-- ON e.student_id = s.student_id 
-- AND e.subject_name = b.subject_name
-- GROUP BY s.student_id, s.student_name, b.subject_name
-- ORDER BY s.student_id, b.subject_name
-- ;

SELECT s.student_id, s.student_name, b.subject_name, IFNULL(e.attended_exams,0) AS attended_exams
FROM Students s
CROSS JOIN Subjects b
LEFT JOIN (
    SELECT ex.student_id, ex.subject_name, COUNT(*) AS attended_exams
    FROM Examinations ex
    GROUP BY ex.student_id, ex.subject_name
) e
ON e.student_id = s.student_id 
AND e.subject_name = b.subject_name
GROUP BY s.student_id, b.subject_name
ORDER BY s.student_id, b.subject_name
;