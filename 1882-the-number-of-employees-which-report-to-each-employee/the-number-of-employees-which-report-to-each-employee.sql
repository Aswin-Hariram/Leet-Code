# Write your MySQL query statement below
with rep as(
    select
        e.employee_id as emp_id,
        e.name as emp_name,
        m.employee_id as manager_id,
        m.name as manager_name,
        e.age as emp_age
    from Employees e
    join Employees m
        on e.reports_to = m.employee_id
)

select
    manager_id as employee_id,
    manager_name as name,
    count(*) as reports_count,
    round(avg(emp_age)) as average_age
from rep
group by manager_id
order by employee_id;