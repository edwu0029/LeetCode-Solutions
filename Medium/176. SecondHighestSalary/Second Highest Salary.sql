/*
LeetCode Medium: 176. Second Highest Salary
https://leetcode.com/problems/second-highest-salary/

Brief Solution Explanation:
- We can use a subquery select to get the maximum salary, then use another
select statement to compare against this maximum salary
- Our final answer is the maximum salary that is less than the total maximum salary
*/
select distinct max(salary) as SecondHighestSalary
from Employee
where salary<(select max(salary) from Employee)