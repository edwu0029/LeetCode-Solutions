/*
LeetCode Easy: 144. Binary Tree Preorder Traversal
https://leetcode.com/problems/binary-tree-preorder-traversal/

Brief Solution Explanation:
N = Number of nodes in binary tree
- Preorder traversal requires us to add/process notes in the following order
    1. The current node
    2. The left subtree
    3. The right subtree
- We can simply use a dfs to follow this traversal order starting from the root
- Let us save the order we visit notes in a list called preorder which we return

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        dfs(root, preorder);
        return preorder;
    }
    void dfs(TreeNode* root, vector<int> &preorder){
        if(root==NULL){
            return;
        }
        preorder.push_back(root->val);
        dfs(root->left, preorder);
        dfs(root->right, preorder);
    }
};