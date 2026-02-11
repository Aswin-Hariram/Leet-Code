SELECT 
    e.employee_id,
    e.department_id
FROM Employee e
WHERE e.primary_flag = 'Y'

UNION

SELECT 
    employee_id,
    department_id
FROM (
    SELECT employee_id,department_id,primary_flag
    FROM Employee
    GROUP BY employee_id
    HAVING COUNT(*) = 1
) t
WHERE primary_flag = 'N';
