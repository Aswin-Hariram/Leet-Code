# Write your MySQL query statement below
with free as (
    select 
        user_id,
        round(sum(activity_duration)/count(*),2) trial_avg_duration
    from UserActivity
    where activity_type = 'free_trial'
    group by user_id
),
paid as (
    select 
        user_id,
        round(sum(activity_duration)/count(*),2) as paid_avg_duration
    from UserActivity
    where activity_type = 'paid'
    group by user_id
)
select 
    p.user_id,
    trial_avg_duration,
    paid_avg_duration
from paid p
join free f
    on p.user_id = f.user_id;
