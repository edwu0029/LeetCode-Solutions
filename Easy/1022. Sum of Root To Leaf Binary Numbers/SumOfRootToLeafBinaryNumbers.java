/*
LeetCode Easy: 1022. Sum of Root To Leaf Binary Numbers
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

Check SumOfRootToLeafBinaryNumbers.cpp for brief solution explanation.
*/
class Solution {
    public int dfs(TreeNode root, int val){
        if(root==null){
            return 0;
        }
        val = (val<<1)+root.val;
        if(root.left==root.right){
            return val;
        }else{
            return dfs(root.left, val)+dfs(root.right, val);
        }
    }
    public int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }
}