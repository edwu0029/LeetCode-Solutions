/*
LeetCode Easy: 993. Cousins in Binary Tree
https://leetcode.com/problems/cousins-in-binary-tree/

Check CousinsInBinaryTree.cpp for brief solution explanation.
*/
class Solution {
    public int parent_x = -1, parent_y = -1, depth_x = 0, depth_y = 0;
    public void dfs(TreeNode root, int parent, int depth, int x, int y){
        if(root==null){
            return;
        }
        if(root.val==x){
            parent_x = parent;
            depth_x = depth;
        }else if(root.val==y){
            parent_y = parent;
            depth_y = depth;
        }else{
            dfs(root.left, root.val, depth+1, x, y);
            dfs(root.right, root.val, depth+1, x, y);
        }
    }
    public boolean isCousins(TreeNode root, int x, int y) {
        dfs(root, -1, 0, x, y);
        if(parent_x!=parent_y&&depth_x==depth_y){
            return true;
        }else{
            return false;
        }
    }
}