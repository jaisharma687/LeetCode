# Write your MySQL query statement below
SELECT t.id
FROM Weather t
JOIN Weather y
WHERE Datediff(t.recordDate, y.recordDate) = 1
AND t.temperature > y.temperature
;