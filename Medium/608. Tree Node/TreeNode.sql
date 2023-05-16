/*
LeetCode Medium: 608. Tree Node
https://leetcode.com/problems/tree-node/

Brief Solution Explanation:
- We can tell a node's type by looking at its id and p_id
    - Root: The only node that's p_id is NULL
    - Inner: the id must be some other node's p_id, additionaly its p_id can't be NULL
    - Leaf: If not Root or Inner, it must be a Leaf
- We can implement this logic inside a case of a select query on the Tree table
    - For checking inner, we can simply tell if a id is some other node's p_id by using
    the IN operator by:
    - id in (select p_id from Tree)
*/
select id, 
case
    when p_id is null then 'Root'
    when id in (select p_id from Tree) then 'Inner'
    else 'Leaf'
end as type
from Tree;