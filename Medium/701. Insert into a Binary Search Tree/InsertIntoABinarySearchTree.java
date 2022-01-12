/*
LeetCode Medium: 701. Insert into a Binary Search Tree
https://leetcode.com/problems/insert-into-a-binary-search-tree/

Check InsertIntoABinarySearchTree.cpp for brief solution explanation.
*/
class Solution {
    public TreeNode traverse(TreeNode root, int val){
        if(root==null){
            return new TreeNode(val);
        }
        if(val<root.val){
            root.left = traverse(root.left, val);
        }else{
            root.right = traverse(root.right, val);
        }
        return root;
    }
    public TreeNode insertIntoBST(TreeNode root, int val) {
        root = traverse(root, val);
        return root;
    }
}