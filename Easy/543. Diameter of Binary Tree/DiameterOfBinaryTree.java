/*
LeetCode Easy: 543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/

Check DiameterOfBinaryTree.cpp for brief solution explanation.
*/
class Solution {
    int ans = 0;
    int dfs(TreeNode root){
        if(root==null){
            return 0;
        }
        int left = dfs(root.left), right = dfs(root.right);
        ans = Math.max(ans, left+right);
        return Math.max(left, right)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ans;
    }
}