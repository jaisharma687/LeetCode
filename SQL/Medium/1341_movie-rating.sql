# Write your MySQL query statement below
SELECT name AS results
FROM (
    SELECT 
        mr.user_id,
        u.name,
        COUNT(mr.movie_id) AS num_reviews
    FROM MovieRating mr
    LEFT JOIN Users u
    ON mr.user_id = u.user_id
    GROUP BY mr.user_id
    ORDER BY num_reviews DESC, name
    LIMIT 1
) T1
UNION ALL
SELECT title AS results
FROM (
    SELECT
        mr.movie_id,
        m.title,
        SUM(mr.rating) / COUNT(mr.rating) AS avg_rating,
        created_at
    FROM MovieRating mr
    LEFT JOIN Movies m
    ON mr.movie_id = m.movie_id
    WHERE YEAR(mr.created_at) = 2020 
    AND MONTH(mr.created_at) = 2
    GROUP BY mr.movie_id
    ORDER BY avg_rating DESC, m.title
    LIMIT 1
) T2
;