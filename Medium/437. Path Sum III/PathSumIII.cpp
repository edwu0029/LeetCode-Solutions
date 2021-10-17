/*
LeetCode Medium: 437. Path Sum III
https://leetcode.com/problems/path-sum-iii/

Brief Solution Explanation:
N = Number of nodes
- To do this problem, we can use a prefix-sum approach on the binary tree, allowing us to query the sum of paths
in O(1) time
- Let us attach a dummy node of value 0 to the root node, this will help us do prefix sums that include the
root node's value
- We can then traverse down the tree from the root and calculate the current prefix sum(Whichh we can call cur_sum) of the path
from the root
    - Keep track of the frequency of previous prefix sum values in a hash map
    - We can then check if there are any paths of sum targetSum that end at our current node
    - To do this, we can calculate the previous prefix sum value(Which we can call prev_sum) we need such that:
    cur_sum-prev_sum = targetSum
    prev_sum = cur_sum-targetSum
    - Thus, the number of paths of sum targetSum that end at our current node is equal to the number of 
    occurences of cur_sum-targetSum in our hash map
    - Once we have processed this node, we can add the current prefix sum to our hash map and move onto
    the left and right children recursively
    - After we are done with the left and right children, we have to remove the current prefix sum from our
    hash map

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    int dfs(TreeNode* root, long long prev_sum, unordered_map<long long, int>& prefix_sums, int targetSum){
        if(root==NULL){
            return 0;
        }
        int ans = 0;
        long long cur_sum = prev_sum+root->val;
        ans+=prefix_sums[cur_sum-targetSum];
        //Add the current prefix sum
        prefix_sums[cur_sum]++;
        //Move to left child
        ans+=dfs(root->left, cur_sum, prefix_sums, targetSum); //Move to left child
        //Move to right child
        ans+=dfs(root->right, cur_sum, prefix_sums, targetSum);
        //Remove the current prefix sum
        prefix_sums[cur_sum]--;
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int>prefix_sums;
        //prefix_sums[i] = Frequency of previous prefix sums of value i
        prefix_sums[0] = 1;
        return dfs(root, 0, prefix_sums, targetSum);
    }
};