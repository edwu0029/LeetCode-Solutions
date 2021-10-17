'''
LeetCode Medium: 1008. Construct Binary Search Tree from Preorder Traversal
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

Check ConstructBinarySearchTreeFromPreorderTraversal.cpp for brief solution explanation.
'''
class Solution:
    def buildBST(self, preorder, u_bound) -> Optional[TreeNode]:
        if self.idx==len(preorder) or preorder[self.idx]>u_bound:
            return None
        root = TreeNode(preorder[self.idx])
        self.idx+=1
        root.left = self.buildBST(preorder, root.val)
        root.right = self.buildBST(preorder, u_bound)
        return root
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        self.idx = 0
        # Arbitrary large intial upper bound
        return self.buildBST(preorder, (1<<31))