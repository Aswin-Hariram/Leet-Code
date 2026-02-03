# Write your MySQL query statement below

with new_table as (
select
customer_id,
time(order_timestamp) as order_time,
order_amount,
payment_method,
order_rating
from restaurant_orders
),

master_table as (
select
customer_id,
count(customer_id) as total_orders,
sum(case when order_time >= '11:00:00' and order_time <= '14:00:00' then 1 else 0 end) as afternoon_hour,
sum(case when order_time >= '18:00:00' and order_time <= '21:00:00' then 1 else 0 end) as evening_hour,
round(avg(order_rating), 2) as avg_rating,
count(order_rating) as total_rating,
count(order_rating) / count(customer_id) * 100 as rating_percentage
from new_table
group by customer_id
)

select
customer_id,
total_orders,
round(((afternoon_hour + evening_hour) / total_orders) * 100) as peak_hour_percentage,
avg_rating as average_rating
from master_table
where rating_percentage >= 50
having total_orders >= 3
and peak_hour_percentage >= 60
and average_rating >= 4.0
order by average_rating desc, customer_id desc;