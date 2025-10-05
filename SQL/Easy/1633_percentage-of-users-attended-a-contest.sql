# Write your MySQL query statement below
SELECT contest_id, ROUND(COUNT(DISTINCT(r.user_id))*100/ 
    (SELECT COUNT(*) FROM Users),2) AS percentage
FROM Register r
GROUP BY contest_id
ORDER BY percentage DESC, contest_id
;