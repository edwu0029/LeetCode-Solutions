/*
LeetCode Medium: 437. Path Sum III
https://leetcode.com/problems/path-sum-iii/

Check PathSumIII.cpp for brief solution explanation.
*/
class Solution {
    public int dfs(TreeNode root, long prev_sum, HashMap<Long, Integer> prefix_sums, int targetSum){
        if(root==null){
            return 0;
        }
        int ans = 0;
        long cur_sum = prev_sum+root.val;
        ans+=prefix_sums.getOrDefault(cur_sum-targetSum, 0);
        prefix_sums.put(cur_sum, prefix_sums.getOrDefault(cur_sum, 0)+1);
        ans+=dfs(root.left, cur_sum, prefix_sums, targetSum);
        ans+=dfs(root.right, cur_sum, prefix_sums, targetSum);
        prefix_sums.put(cur_sum, prefix_sums.get(cur_sum)-1);
        return ans;
    }
    public int pathSum(TreeNode root, int targetSum) {
        HashMap<Long, Integer>prefix_sums = new HashMap<Long, Integer>();
        prefix_sums.put((long)0, 1);
        return dfs(root, 0, prefix_sums, targetSum);
    }
}