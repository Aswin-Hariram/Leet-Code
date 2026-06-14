# Write your MySQL query statement below
select  
    e.name as Employee   
from Employee e
left join Employee m
    on e.managerId = m.id
where 
    not isnull(e.managerId) and
    e.salary>m.salary;