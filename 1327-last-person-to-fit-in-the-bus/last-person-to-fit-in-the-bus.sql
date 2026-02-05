SELECT Name as person_name
FROM (
    SELECT
        turn AS Turn,
        person_id AS ID,
        person_name AS Name,
        weight,
        SUM(weight) OVER (
            ORDER BY turn
            ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
        ) AS total_weight
    FROM Queue
    ORDER BY Turn
) q
WHERE total_weight <= 1000
order by total_weight desc
limit 1;

