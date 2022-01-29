/*
LeetCode Easy: 1022. Sum of Root To Leaf Binary Numbers
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

Brief Solution Explanation:
N = Number of total nodes
- We can use dfs to traverse each node and process the in one go
    - We can accumulate our answer up to the current node, lets call this val
    - Shift val one bit to the left(multplying by 2), then add the current node's value
    - Then we recursively move to the left and right nodes
    - If the current node is a leaf node, left and right children are equal to null, then the answer
    for the current path is val

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int dfs(TreeNode* root, int val){
        if(root==NULL){
            return 0;
        }
        val = (val<<1)+root->val;
        if(root->left==root->right){ //Check if current node is a leaf node
            return val;
        }else{
            return dfs(root->left, val)+dfs(root->right, val);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};