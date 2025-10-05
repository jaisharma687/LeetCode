# Write your MySQL query statement below
SELECT
    t.id,
    CASE
        WHEN t.p_id IS NULL THEN  "Root"
        WHEN t.id NOT IN (
            SELECT dt.p_id FROM Tree dt WHERE dt.p_id IS NOT NULL
        ) THEN "Leaf"
        ELSE "Inner"
    END AS type
FROM Tree t
;