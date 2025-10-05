# Write your MySQL query statement below
SELECT p.product_id, p.product_name
FROM Product p
LEFT JOIN Sales s
ON p.product_id = s.product_id
GROUP BY p.product_id
HAVING MIN(s.sale_date) >= '2019-01-01'
AND MAX(s.sale_date) <= '2019-03-31'
;

-- SELECT p.product_id, p.product_name
-- FROM Product p
-- LEFT JOIN Sales s
-- ON p.product_id = s.product_id
-- WHERE s.seller_id IS NOT NULL
-- AND p.product_id NOT IN (
--     SELECT p.product_id
--     FROM Sales s
--     LEFT JOIN Product p
--     ON p.product_id = s.product_id
--     WHERE s.sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31'
-- )
-- GROUP BY p.product_id
-- ;