# Write your MySQL query statement below
Select name from Employee
where id in (select managerId from Employee
group by managerId
having count(managerId)>=5)