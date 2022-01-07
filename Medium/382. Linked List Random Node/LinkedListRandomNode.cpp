/*
LeetCode Medium: 382. Linked List Random Node
https://leetcode.com/problems/linked-list-random-node/

Brief Solution Explanation:
- First, let us conver the linked list to an array. This can help us access elements at specific indices more easily
- This can be done in the constructor of the class by starting at the head, adding the value of the head and moving the
head to the next element in the linked list
- To get a random node, we can use built-in random number generators to generate a index between 0 to arr.size()
*/
class Solution {
public:
    vector<int>arr;
    Solution(ListNode* head) {
        while(head!=NULL){
            arr.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};