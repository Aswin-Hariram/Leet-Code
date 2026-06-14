# Write your MySQL query statement below

select
   
    t.id
from Weather y
join Weather t
    ON DATE_ADD(y.recordDate, INTERVAL 1 DAY) = t.recordDate
where y.temperature < t.temperature;