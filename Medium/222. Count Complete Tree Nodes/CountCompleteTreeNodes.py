'''
LeetCode Medium: 222. Count Complete Tree Nodes
https://leetcode.com/problems/count-complete-tree-nodes/

Check CountCompleteTreeNodes.cpp for brief solution explanation.
'''
class Solution:
    def lft_depth(self, root):
        if not root:
            return 0
        return 1+self.lft_depth(root.left)
    def countNodes(self, root):
        if not root:
            return 0
        lft = self.lft_depth(root.left)
        rht = self.lft_depth(root.right)
        if lft==rht:
            return pow(2, lft)+self.countNodes(root.right)
        else:
            return pow(2, rht)+self.countNodes(root.left)