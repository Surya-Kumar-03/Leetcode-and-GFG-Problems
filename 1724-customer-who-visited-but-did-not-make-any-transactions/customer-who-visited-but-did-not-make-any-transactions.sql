# Write your MySQL query statement below
SELECT v.customer_id, Count(v.visit_id) as count_no_trans
from Visits as v
Left join Transactions as t
ON v.visit_id = t.visit_id
where t.transaction_id is null
group by v.customer_id;