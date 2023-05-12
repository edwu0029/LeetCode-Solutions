/*
LeetCode Easy: 1757. Recyclable and Low Fat Products
https://leetcode.com/problems/recyclable-and-low-fat-products/
*/

select product_id
from  Products
where low_fats=1 and recyclable=1;