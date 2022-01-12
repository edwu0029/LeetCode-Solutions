/*
LeetCode Medium: 701. Insert into a Binary Search Tree
https://leetcode.com/problems/insert-into-a-binary-search-tree/

Brief Solution Explanation:
H = Height of BST
- We can find the location of where our val should fall by traversing the BST:
    - Let root be our current node
    - If our root==null, then we have arrived at where val should be inserted. We can make a new TreeNode here
    - If val<root.val, then  val needs to be in the left subtree of root. We can move to root.left and
    continue traversing
    - Otherwise, val needs to be in the right subtreee of root. We can move to root.right and continue traversing

Time Complexity: O(H)
*/
class Solution {
public:
    TreeNode* traverse(TreeNode* root, int val){
        if(root==NULL){
            return new TreeNode(val);
        }
        if(val<root->val){
            root->left = traverse(root->left, val);
        }else{
            root->right = traverse(root->right, val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        root = traverse(root, val);
        return root;
    }
};