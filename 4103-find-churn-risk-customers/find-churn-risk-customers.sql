WITH last_event AS (
    SELECT
        user_id,
        plan_name      AS current_plan,
        monthly_amount AS current_monthly_amount,
        event_type,
        event_date,
        ROW_NUMBER() OVER (
            PARTITION BY user_id
            ORDER BY event_date DESC, event_id DESC
        ) AS rn
    FROM subscription_events
),
user_stats AS (
    SELECT
        user_id,
        MAX(monthly_amount) AS max_historical_amount,
        MIN(event_date)     AS first_date,
        MAX(event_date)     AS last_date,
        SUM(event_type = 'downgrade') AS downgrade_cnt
    FROM subscription_events
    GROUP BY user_id
)

SELECT
    l.user_id,
    l.current_plan,
    l.current_monthly_amount,
    u.max_historical_amount,
    DATEDIFF(u.last_date, u.first_date) AS days_as_subscriber
FROM last_event l
JOIN user_stats u
    ON l.user_id = u.user_id
WHERE l.rn = 1
  AND l.event_type <> 'cancel'                 -- currently active
  AND u.downgrade_cnt >= 1                     -- at least one downgrade
  AND l.current_monthly_amount < 0.5 * u.max_historical_amount
  AND DATEDIFF(u.last_date, u.first_date) >= 60
ORDER BY
    days_as_subscriber DESC,
    l.user_id ASC;
