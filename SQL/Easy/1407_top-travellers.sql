# Write your MySQL query statement below
SELECT u.name, IFNULL(t.travelled_distance,0) AS travelled_distance
FROM Users u
LEFT JOIN (
    SELECT user_id, SUM(distance) as travelled_distance
    FROM Rides
    GROUP BY user_id
) t
ON u.id = t.user_id
ORDER BY t.travelled_distance DESC, name
;