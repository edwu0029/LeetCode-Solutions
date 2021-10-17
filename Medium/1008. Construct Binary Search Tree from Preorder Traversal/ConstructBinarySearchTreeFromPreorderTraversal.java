/*
LeetCode Medium: 1008. Construct Binary Search Tree from Preorder Traversal
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

Check ConstructBinarySearchTreeFromPreorderTraversal.cpp for brief solution explanation.
*/
class Solution {
    int idx;
    public TreeNode buildBST(int[]preorder, int u_bound){
        if(idx==preorder.length||preorder[idx]>u_bound){
            return null;
        }
        TreeNode root = new TreeNode(preorder[idx++]);
        root.left = buildBST(preorder, root.val);
        root.right = buildBST(preorder, u_bound);
        return root;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        this.idx = 0;
        return buildBST(preorder, Integer.MAX_VALUE);
    }
}