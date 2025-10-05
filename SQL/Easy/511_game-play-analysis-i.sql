# Write your MySQL query statement below

-- SELECT player_id, MIN(event_date) AS first_login
-- FROM Activity
-- GROUP BY player_id;

SELECT t.player_id, t.event_date AS first_login
FROM (
    SELECT player_id, event_date,
        ROW_NUMBER() OVER (
            PARTITION BY player_id
            ORDER BY event_date ASC
        ) AS rn
    FROM Activity
) t
WHERE t.rn = 1;