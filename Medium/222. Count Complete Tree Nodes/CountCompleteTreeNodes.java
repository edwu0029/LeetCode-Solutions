/*
LeetCode Medium: 222. Count Complete Tree Nodes
https://leetcode.com/problems/count-complete-tree-nodes/

Check CountCompleteTreeNodes.cpp for brief solution explanation.
*/
class Solution {
    public int lft_depth(TreeNode root){
        if(root==null){
            return 0;
        }
        return 1+lft_depth(root.left);
    }
    public int countNodes(TreeNode root) {
        if(root==null){
            return 0;
        }
        int lft = lft_depth(root.left), rht = lft_depth(root.right);
        if(lft==rht){
            return (1<<lft)+countNodes(root.right);
        }else{
            return (1<<rht)+countNodes(root.left);
        }
    }
}