/*
LeetCode Easy: 993. Cousins in Binary Tree
https://leetcode.com/problems/cousins-in-binary-tree/

Brief Solution Explanation:
N = Number of nodes
- Use a dfs(depth-first search) to traverse the binary tree and when we reach either one
of the target nodes, we can update their parent and depth information
    - Note that if we reach a target node, we don't need to traverse and nodes in its subtree
    since the other target node won't exist there

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int parent_x = -1, parent_y = -1, depth_x = 0, depth_y = 0;
    void dfs(TreeNode* root, int parent, int depth, int x, int y){
        if(root==NULL){
            return;
        }
        if(root->val==x){
            parent_x = parent;
            depth_x = depth;
        }else if(root->val==y){
            parent_y = parent;
            depth_y = depth;
        }else{
            dfs(root->left, root->val, depth+1, x, y);
            dfs(root->right, root->val, depth+1, x, y);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, -1, 0, x, y);
        if(parent_x!=parent_y&&depth_x==depth_y){
            return true;
        }else{
            return false;
        }
    }
};