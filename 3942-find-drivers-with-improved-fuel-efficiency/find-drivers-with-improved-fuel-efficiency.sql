WITH first_half AS (
    SELECT
        d.driver_id,
        d.driver_name,
        AVG(t.distance_km / t.fuel_consumed) AS first_avg
    FROM drivers d
    JOIN trips t
        ON d.driver_id = t.driver_id
    WHERE MONTH(t.trip_date) <= 6
    GROUP BY d.driver_id, d.driver_name
),
second_half AS (
    SELECT
        d.driver_id,
        d.driver_name,
        AVG(t.distance_km / t.fuel_consumed) AS second_avg
    FROM drivers d
    JOIN trips t
        ON d.driver_id = t.driver_id
    WHERE MONTH(t.trip_date) > 6
    GROUP BY d.driver_id, d.driver_name
)

SELECT
    f.driver_id,
    f.driver_name,
    ROUND(f.first_avg, 2) AS first_half_avg,
    ROUND(s.second_avg, 2) AS second_half_avg,
    ROUND(s.second_avg - f.first_avg, 2) AS efficiency_improvement
FROM first_half f
JOIN second_half s
    ON f.driver_id = s.driver_id
WHERE s.second_avg > f.first_avg
ORDER BY efficiency_improvement DESC, f.driver_name;
