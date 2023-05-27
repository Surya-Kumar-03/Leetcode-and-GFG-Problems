# Write your MySQL query statement below
select distinct a.Id
from Weather a, Weather b
where a.Temperature > b.Temperature
and datediff(a.Recorddate, b.Recorddate) = 1