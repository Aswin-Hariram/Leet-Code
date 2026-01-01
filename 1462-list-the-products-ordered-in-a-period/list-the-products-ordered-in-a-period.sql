# Write your MySQL query statement below
select 
    p.product_name,
    sum(o.unit) as unit
from Products p
left join Orders o
    on p.product_id = o.product_id
where 
    Month(o.order_date) = 2 and
    Year(o.order_date) = 2020
group by
    p.product_id
having sum(o.unit) >=100;