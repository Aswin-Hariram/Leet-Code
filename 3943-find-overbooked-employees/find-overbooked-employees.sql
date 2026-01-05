WITH weekly_meetings AS (
    SELECT 
        employee_id,
        YEAR(meeting_date) AS yr,
        WEEK(meeting_date, 1) AS week_no,
        SUM(duration_hours) AS total_hours
    FROM meetings
    GROUP BY employee_id, YEAR(meeting_date), WEEK(meeting_date, 1)
    HAVING SUM(duration_hours) > 20
)
SELECT 
    e.employee_id,
    e.employee_name,
    e.department,
    COUNT(*) AS meeting_heavy_weeks
FROM weekly_meetings w
JOIN employees e
    ON w.employee_id = e.employee_id
GROUP BY e.employee_id, e.employee_name, e.department
HAVING COUNT(*) >= 2
ORDER BY meeting_heavy_weeks DESC, e.employee_name ASC;
