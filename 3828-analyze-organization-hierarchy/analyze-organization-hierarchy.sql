WITH RECURSIVE
-- 1️⃣ Determine hierarchy level
temp_l AS (
    SELECT 
        employee_id,
        employee_name,
        manager_id,
        1 AS level
    FROM Employees
    WHERE manager_id IS NULL       -- CEO

    UNION ALL
    SELECT
        e.employee_id,
        e.employee_name,
        e.manager_id,
        l.level + 1 AS level
    FROM Employees e
    JOIN temp_l l
        ON e.manager_id = l.employee_id
),

-- 2️⃣ Build recursive subordinate tree
temp_s AS (
    SELECT
        e.employee_id,
        e.employee_name,
        e.employee_id AS sub_id,
        e.salary AS salary
    FROM Employees e

    UNION ALL

    SELECT
        s.employee_id,
        s.employee_name,
        e.employee_id AS sub_id,
        e.salary AS salary
    FROM Employees e
    JOIN temp_s s
        ON s.sub_id = e.manager_id
)

-- 3️⃣ Aggregate results
SELECT
    s.employee_id,
    s.employee_name,
    l.level,
    COUNT(*) - 1 AS team_size,          -- subtract self
    SUM(s.salary) AS budget             -- include own salary
FROM temp_s s
JOIN temp_l l
    ON s.employee_id = l.employee_id
GROUP BY
    s.employee_id, s.employee_name, l.level
ORDER BY
    l.level ASC,
    budget DESC,
    s.employee_name ASC;
