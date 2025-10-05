# Write your MySQL query statement below
SELECT customer_id
FROM (
    SELECT
        customer_id,
        CASE
            WHEN COUNT(DISTINCT(product_key)) = (
                SELECT COUNT(DISTINCT(product_key)) FROM Product
            ) THEN 1
            ELSE 0
        END cnt
    FROM Customer
    GROUP BY customer_id
) T
WHERE cnt=1
;