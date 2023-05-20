# Write your MySQL query statement below
select (select distinct Employee.salary 
from Employee
order by salary DESC
limit 1 offset 1) as SecondHighestSalary