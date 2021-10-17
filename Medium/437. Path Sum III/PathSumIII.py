'''
LeetCode Medium: 437. Path Sum III
https://leetcode.com/problems/path-sum-iii/

Check PathSumIII.cpp for brief solution explanation.
'''
class Solution:
    def dfs(self, root, prev_sum, prefix_sums, targetSum) -> int:
        if root==None:
            return 0
        ans, cur_sum = 0, prev_sum+root.val
        if cur_sum-targetSum in prefix_sums:
            ans+=prefix_sums[cur_sum-targetSum]
        if cur_sum in prefix_sums:
            prefix_sums[cur_sum]+=1
        else:
            prefix_sums[cur_sum] = 1
        ans+=self.dfs(root.left, cur_sum, prefix_sums, targetSum)
        ans+=self.dfs(root.right, cur_sum, prefix_sums, targetSum)
        prefix_sums[cur_sum]-=1
        return ans
    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        prefix_sums = {0:1}
        return self.dfs(root, 0, prefix_sums, targetSum)