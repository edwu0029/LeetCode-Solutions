/*
LeetCode Medium: 222. Count Complete Tree Nodes
https://leetcode.com/problems/count-complete-tree-nodes/

Brief Solution Explanation:
N = Length of nums
- We can recursively traverse the binary tree, let us call the current node as root
    - We can then compute the left-side depth of both root.left and root.right, let us call them lft and rht respectively
    - Case 1: If lft==rht, we can conclude that the left subtree of root is guranteed to be a full binary tree
        - From there we can simply add the number of nodes of the left subtree which is mathematically 2^lft-1
        - We still need to plus one extra node for the current root, leaving us with adding 2^lft-1+1 = 2^lft

         |
       *root
        /  \
      *1    2
      / \  /
    *3  *4 5

        - This diagram shows which nodes we are adding to the total if lft==rht
        - We then continue by moving to root.right
    - Case 2: If lft!=rht, we know that the right subtree's last level is empty(Due to the property that in a complete binary tree, 
    all nodes in the last level are as far left as possible)
        - As a result, we know that the right subtree is also a full binary tree, but of one less height than the
        left subtree
        - Similar to case 1, we can just add 2^rht and then move on to the root.left to continue

- It takes O(logN) to traverse the tree and O(logN) to calculate the height for each node traversed
Time Complexity: O(logN*logN)
Memory Complexity: O(1)
*/
class Solution {
public:
    int lft_depth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+lft_depth(root->left);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lft = lft_depth(root->left), rht = lft_depth(root->right);
        if(lft==rht){
            return (1<<lft)+countNodes(root->right);
        }else{
            return (1<<rht)+countNodes(root->left);
        }
    }
};