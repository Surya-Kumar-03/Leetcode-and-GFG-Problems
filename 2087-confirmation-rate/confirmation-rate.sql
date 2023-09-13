# Write your MySQL query statement below
select s.user_id, round(avg(if(c.action="confirmed",1,0)), 2) as confirmation_rate
from Signups as s
left join Confirmations as c
on c.user_id = s.user_id
group by s.user_id;