SELECT 
    e.employee_id,
    e.department_id
FROM Employee e
WHERE e.primary_flag = 'Y'

UNION

SELECT 
    e.employee_id,
    e.department_id
FROM Employee e
JOIN (
    SELECT employee_id
    FROM Employee
    GROUP BY employee_id
    HAVING COUNT(*) = 1
) c
ON e.employee_id = c.employee_id
WHERE e.primary_flag = 'N';
