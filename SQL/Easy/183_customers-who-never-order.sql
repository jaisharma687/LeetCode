# Write your MySQL query statement below

-- SELECT c.name AS Customers
-- FROM Customers c
-- LEFT JOIN Orders o
-- ON c.id = o.customerId
-- WHERE o.id IS NULL;

SELECT c.name AS Customers
FROM Customers c
WHERE c.id 
NOT IN (
    SELECT o.customerId
    FROM Orders o
);