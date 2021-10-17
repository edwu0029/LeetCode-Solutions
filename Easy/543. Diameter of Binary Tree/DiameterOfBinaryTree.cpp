/*
LeetCode Easy: 543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/

Brief Solution Explanation:
N = Number of nodes
- The diameter of a binary tree at some node will be the height of the left subtree + height of right subtree
- We can traverse the binary tree from bottom up and calculate the heights of each subtree recursively, keeping
track of the maximum diameter

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int dfs(TreeNode *root, int& ans){
        if(root==NULL){
            return 0;
        }
        int left = dfs(root->left, ans), right = dfs(root->right, ans);
        ans = max(ans, left+right);
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};