# Write your MySQL query statement below
SELECT ROUND(SUM(DATEDIFF(b.event_date, a.first_login)=1) / COUNT(DISTINCT(a.player_id)),2) AS fraction
FROM (
    SELECT 
        player_id,
        MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) a
LEFT JOIN Activity b
ON a.player_id = b.player_id
;