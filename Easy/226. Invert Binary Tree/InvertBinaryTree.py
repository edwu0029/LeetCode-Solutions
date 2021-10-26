'''
LeetCode Easy: 226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/

Check InvertBinaryTree.cpp for brief solution explanation.
'''
class Solution:
    def dfs(self, root):
        if root==None:
            return
        self.dfs(root.left)
        self.dfs(root.right)
        root.left, root.right = root.right, root.left
    
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.dfs(root)
        return root