WITH all_users AS (
    SELECT COUNT(DISTINCT user_id) AS total_users
    FROM Users
)
SELECT 
    r.contest_id,
    round(COUNT(DISTINCT r.user_id)/(SELECT total_users FROM all_users) * 100,2) as percentage
FROM Register r
GROUP BY r.contest_id
order by percentage desc,r.contest_id;
