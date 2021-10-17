/*
LeetCode Medium: 1008. Construct Binary Search Tree from Preorder Traversal
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

Brief Solution Explanation:
N = Number of nodes/Length of preorder traversal
- Note: Preorder traversal is such that: current node, left, right
- There are many well documented methods to build BSTs from different traversals(preorder, inorder, postorder),
here is one such article:
https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

- We can simply loop through the preorder traversal and recursively build the binary search tree
    - For each element, we can create a Node with the given value
    - Keep track of the upper bound for this node; it's children's values can't exceed that upper bound
    - Next we move to the left child, who's upper bound is now our node's value
        - Taking care of all elements x where x.val<node.val
    - Finally we move to the right child, who's upper bound is still the current node's upper bound
        - Taking care of all elements x where node.val<=x.val<upper bound

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    TreeNode* buildBST(vector<int>& preorder, int &idx, int u_bound){
        if(idx==preorder.size()||preorder[idx]>u_bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = buildBST(preorder, idx, root->val);
        root->right = buildBST(preorder, idx, u_bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        //Intial upper bound is INT_MAX
        return buildBST(preorder, idx, INT_MAX);
    }
};