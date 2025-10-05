# Write your MySQL query statement below
SELECT DISTINCT L.num AS ConsecutiveNums
FROM (
    SELECT num,
        LAG(num) OVER (ORDER by id) AS 'lag',
        LEAD(num) OVER (ORDER by id) AS 'lead'
    FROM Logs
) L
WHERE L.lag = L.num
AND L.num = L.lead
;