# Write your MySQL query statement below
-- SELECT customer_id, COUNT(v.visit_id) - SUM(IFNULL(trans_visits,0)) AS count_no_trans
-- FROM Visits v
-- LEFT JOIN (
--     SELECT visit_id , COUNT(DISTINCT(visit_id)) AS trans_visits
--     FROM Transactions
--     GROUP BY visit_id
-- ) t
-- ON v.visit_id = t.visit_id
-- GROUP BY customer_id
-- HAVING count_no_trans>0
-- ;

SELECT customer_id, COUNT(v.visit_id) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id
;