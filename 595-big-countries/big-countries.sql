# Write your MySQL query statement below
select
    w.name,
    w.population,
    w.area
from World w
where 
    area >= 3000000 or
    population >= 25000000;