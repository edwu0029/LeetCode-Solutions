'''
LeetCode Easy: 543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/

Check DiameterOfBinaryTree.cpp for brief solution explanation.
'''
class Solution:
    def dfs(self, root) -> int:
        if root==None:
            return 0
        left, right = self.dfs(root.left), self.dfs(root.right)
        self.ans = max(self.ans, left+right)
        return max(left, right)+1
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        self.dfs(root)
        return self.ans