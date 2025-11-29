# Write your MySQL query statement below
select 
    actor_id,
    director_id
from(
    select 
    actor_id,
    director_id,
    count(*) as Count
    from ActorDirector
    group by actor_id,director_id
) as t
where Count>=3;

