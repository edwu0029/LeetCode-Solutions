'''
LeetCode Easy: 993. Cousins in Binary Tree
https://leetcode.com/problems/cousins-in-binary-tree/

Check CousinsInBinaryTree.cpp for brief solution explanation.
'''
class Solution:
    def dfs(self, root, parent, depth, x, y):
        if root==None:
            return
        if root.val==x:
            self.parent_x = parent
            self.depth_x = depth
        elif root.val==y:
            self.parent_y = parent
            self.depth_y = depth
        else:
            self.dfs(root.left, root.val, depth+1, x, y)
            self.dfs(root.right, root.val, depth+1, x, y)
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        self.parent_x = self.parent_y = -1
        self.depth_x = self.depth_y = 0
        self.dfs(root, -1, 0, x, y)
        if self.parent_x!=self.parent_y and self.depth_x==self.depth_y:
            return True
        else:
            return False