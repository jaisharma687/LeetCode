# Write your MySQL query statement below
WITH t AS (
    SELECT
        *,
        id - ROW_NUMBER() OVER () AS id_diff
    FROM Stadium
    WHERE people >= 100
)
SELECT
    id,
    visit_date,
    people
FROM t
WHERE id_diff IN (
    SELECT id_diff
    FROM t
    GROUP BY id_diff
    HAVING COUNT(id_diff)>=3
)
;