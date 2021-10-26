/*
LeetCode Easy: 226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/

Brief Solution Explanation:
- This is a classic interview problem with a well documented method
- We can recursively traverse the tree and for each node we can do the following:
    - If our current node is null, do nothing
    - Invert the left and right subtrees(recursion)
    - Swap the left and right children of the current node
- Finally, we are left with the inverted binary tree and we can return the root TreeNode

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        dfs(root->right);
        swap(root->left, root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};