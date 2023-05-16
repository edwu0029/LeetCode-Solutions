/*
LeetCode Medium: 1158. Market Analysis I
https://leetcode.com/problems/market-analysis-i/

Brief Solution Explanation:
- We need to use a left join (Since we need to include all users, regardless of if they made a order or not)
to join the Users and Orders table by the user_id/buyer_id common column with:
    - Left: Users
    - Right: Orders
- Notice that the Items table is actually redundant for this problem
- we can then aggregate to only count orders in the year 2019 for each user using a group by user_id
*/
select user_id as buyer_id, join_date, sum(
  case
    when year(order_date)=2019 then 1
    else 0
  end
) as orders_in_2019 
from (Users left join Orders on Users.user_id=Orders.buyer_id)
group by user_id