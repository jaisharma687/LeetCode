# Write your MySQL query statement below
SELECT 
    s.user_id,
    IFNULL(t.confirmation_rate,0) AS confirmation_rate
FROM Signups s
LEFT JOIN (
    SELECT
        user_id,
        ROUND(COUNT(CASE WHEN action="confirmed" THEN 1 END) / COUNT(action),2) AS confirmation_rate
    FROM Confirmations
    GROUP BY user_id
) t
ON t.user_id = s.user_id
;