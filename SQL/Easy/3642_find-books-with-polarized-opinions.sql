# Write your MySQL query statement below
SELECT
    b.book_id,
    b.title,
    b.author,
    b.genre,
    b.pages,
    t.rating_spread,
    t.polarization_score
FROM books b
LEFT JOIN (
    SELECT
        *,
        MAX(session_rating) - MIN(session_rating) AS rating_spread,
        ROUND(COUNT(CASE WHEN session_rating>=4 OR session_rating<=2 THEN 1 END) / COUNT(*),2) AS polarization_score
    FROM reading_sessions
    GROUP BY book_id
    HAVING COUNT(*)>=5
    AND MAX(session_rating)>=4
    AND MIN(session_rating)<=2
    AND polarization_score >= 0.6
) t
ON b.book_id = t.book_id
WHERE t.rating_spread IS NOT NULL
AND t.polarization_score IS NOT NULL
ORDER BY t.polarization_score DESC, b.title DESC
;