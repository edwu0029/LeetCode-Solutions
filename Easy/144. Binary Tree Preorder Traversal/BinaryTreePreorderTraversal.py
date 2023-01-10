'''
LeetCode Easy: 144. Binary Tree Preorder Traversal
https://leetcode.com/problems/binary-tree-preorder-traversal/

Check BinaryTreePreorderTraversal.cpp for brief solution explanation.
'''
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        preorder = []
        self.dfs(root, preorder)
        return preorder
    def dfs(self, root, preorder):
        if root==None:
            return
        preorder.append(root.val)
        self.dfs(root.left, preorder)
        self.dfs(root.right, preorder)