'''
LeetCode Easy: 1022. Sum of Root To Leaf Binary Numbers
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

Check SumOfRootToLeafBinaryNumbers.cpp for brief solution explanation.
'''
class Solution:
    def dfs(self, root, val) -> int:
        if root==None:
            return 0
        val = (val<<1)+root.val
        if root.left==root.right:
            return val
        else:
            return self.dfs(root.left, val)+self.dfs(root.right, val)

    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root, 0)