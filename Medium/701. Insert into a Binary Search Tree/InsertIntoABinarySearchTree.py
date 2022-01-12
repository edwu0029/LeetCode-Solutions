'''
LeetCode Medium: 701. Insert into a Binary Search Tree
https://leetcode.com/problems/insert-into-a-binary-search-tree/

Check InsertIntoABinarySearchTree.cpp for brief solution explanation.
'''
class Solution:
    def traverse(self, root, val) -> Optional[TreeNode]:
        if root==None:
            return TreeNode(val)
        if val<root.val:
            root.left = self.traverse(root.left, val)
        else:
            root.right = self.traverse(root.right, val)
        return root

    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        root = self.traverse(root, val)
        return root