/*
LeetCode Medium: 2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/

Brief Solution Explanation:
N = Length of l1
M = Length of l2
- Since N and M can go up to 100 digits, we can't evaluate the linked lists to a data type and simply add them
- Instead, we must look digit by digit while keeping track of carried digits, similar to the addition method learned in elementary schools
    - For example, if l1 = [2, 9, 9, 9] and l2 = [2, 4, 3]
    carry 1 1  1
    l1      9 9 9 2
    l2        3 4 2
    ----------------
          1 0 3 3 4
    - In this case, our final answer would be [4, 3, 3, 0, 1]

- Since the linked lists are already ordered from right digit to left digit when traversing, we can simply
iterate through l1 and l2 to generate the final answers digit on that column
- Note that the condition for if the final answer will have a digit in ith column is if any of the following conditions are met:
    1. l1 has a ith digit that is non-zero
    2. l2 has a ith digit that is non-zero
    3. The carry is non-zero
- Let carry be the carried value at the current column
    - carry is intially 0
We can iterate through l1 and l2
    - let res be the sum for the ith column where:
        - res = carry + l1.value (if it exists) + l2.value (if it exists)
    - The final answers digit would be res%10 (since digits are <10) 
    - carry should then be updated to res//10 (integer division) for the next column
    - Continue this iteration until l1 and l2 have both been fully processed
- If the carry after processing l1 and l2 is non-zero, we can add that as the last node 
    - In the example above, this would be for the left-most 1 where l1 and l2 don't exist, but carry is 1
- We can generate the final answer as a linked list as we calcualte each of the digits

Time Complexity: O(max(N, M))
Memory Complexity: O(max(N, M))
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *node = NULL;
        int carry = 0;
        while(l1!=NULL||l2!=NULL){ //Process both l1 and l2
            int res = carry;
            if(l1!=NULL){
                res+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                res+=l2->val;
                l2 = l2->next;
            }
            if(head==NULL){ //To create first ListNode for the answer
                head = new ListNode(res%10);
                node = head;
            }else{
                node->next = new ListNode(res%10);
                node = node->next;
            }
            carry = res/10;
        }
        //If there is a carry remaining, add it as the final node
        if(carry>0){
            node->next = new ListNode(carry);
        }
        return head;
    }
};