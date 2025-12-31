# Write your MySQL query statement below


with poor as(
    select *,count(*) as c from Queries where rating<3
    group by query_name
)

select 
    q.query_name,
    round(sum(q.rating/q.position)/count(*),2) as quality,
    coalesce(round((p.c/count(*))*100,2),0) as poor_query_percentage
from Queries q
left join poor p
on p.query_name = q.query_name
group by query_name;
