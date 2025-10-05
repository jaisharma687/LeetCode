# Write your MySQL query statement below
SELECT u.name, SUM(t.amount) AS balance
FROM Transactions t
LEFT JOIN Users u
ON t.account = u.account
GROUP BY t.account
HAVING balance > 10000
;