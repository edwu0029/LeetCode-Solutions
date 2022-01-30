/*
LeetCode Medium: 430. Flatten a Multilevel Doubly Linked List
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

Brief Solution Explanation:
- We can first traverse the doubly linked list and flatten it into an array
- To do this, we can start at the head and add head.val, then go to head.child recursively, then go to head.next recursively
    - When we add values in that order, we can get the correct flattened array
- Once we have the array, we can simply make the flattened linked list

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    void traverse(Node* head, vector<int>&ans){
        if(head==NULL){
            return;
        }
        ans.push_back(head->val);
        traverse(head->child, ans);
        traverse(head->next, ans);
    }
    Node* flatten(Node* head) {
        if(head==NULL){
            return NULL;
        }
        vector<int>ans;
        traverse(head, ans);
        Node* root = new Node();
        Node* cur = root;
        Node* prev = NULL;
        for(int i = 0;i<ans.size();i++){
            cur->val = ans[i];
            cur->prev = prev;
            if(i!=ans.size()-1){
                cur->next = new Node();
            }
            cur->child = NULL;
            prev = cur;
            cur = cur->next;
        }
        return root;
    }
};