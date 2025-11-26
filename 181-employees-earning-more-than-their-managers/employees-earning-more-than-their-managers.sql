# Write your MySQL query statement below

SELECT 
    e1.name AS Employee
FROM Employee e1
LEFT JOIN Employee e2
    ON e1.managerId = e2.id
WHERE e1.managerId IS NOT NULL
  AND e2.id IS NOT NULL
  AND COALESCE(e1.salary, 0) > COALESCE(e2.salary, 0);
