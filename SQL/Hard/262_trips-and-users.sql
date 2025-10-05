# Write your MySQL query statement below
SELECT 
    request_at AS Day,
    ROUND(COUNT(CASE WHEN status LIKE "cancelled%" THEN 1 END) / COUNT(status),2) AS "Cancellation Rate"
FROM Trips
WHERE client_id IN (SELECT users_id FROM Users WHERE banned="No" AND role="client")
AND driver_id IN (SELECT users_id FROM Users WHERE banned="No" AND role="driver")
AND request_at BETWEEN "2013-10-01" AND "2013-10-03"
GROUP BY request_at
;