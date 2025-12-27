WITH
q1 AS (
    SELECT id, id - ROW_NUMBER() OVER() AS id_diff
    FROM Stadium
    WHERE people > 99
),
q2 AS (
    SELECT *,
           ROW_NUMBER() OVER(PARTITION BY id_diff) AS id_diff_order
    FROM q1
),
q3 AS (
    SELECT id
    FROM q2
    WHERE id_diff IN (
        SELECT id_diff
        FROM q2
        GROUP BY id_diff
        HAVING COUNT(*) >= 3
    )
)
SELECT *
FROM Stadium
WHERE id IN (SELECT id FROM q3)
ORDER BY visit_date;
