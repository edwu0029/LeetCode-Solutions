/*
LeetCode Easy: 226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/

Check InvertBinaryTree.cpp for brief solution explanation.
*/
class Solution {
    public void dfs(TreeNode root){
        if(root!=null){
            dfs(root.left);
            dfs(root.right);
            TreeNode tmp = root.left;
            root.left = root.right;
            root.right = tmp;
        }
    }
    public TreeNode invertTree(TreeNode root) {
        dfs(root);
        return root;
    }
}