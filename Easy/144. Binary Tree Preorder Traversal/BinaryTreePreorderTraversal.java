'''
LeetCode Easy: 144. Binary Tree Preorder Traversal
https://leetcode.com/problems/binary-tree-preorder-traversal/

Check BinaryTreePreorderTraversal.cpp for brief solution explanation.
'''
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer>preorder = new LinkedList<Integer>();
        dfs(root, preorder);
        return preorder;
    }
    public void dfs(TreeNode root, List<Integer>preorder){
        if(root==null){
            return;
        }
        preorder.add(root.val);
        dfs(root.left, preorder);
        dfs(root.right, preorder);
    }
}