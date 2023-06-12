/*
LeetCode Medium: 2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/

Check AddTwoNumbers.cpp for brief solution explanation.
*/
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = null, node = null;
        int carry = 0;
        while(l1!=null||l2!=null){
            int res = carry;
            if(l1!=null){
                res+=l1.val;
                l1 = l1.next;
            }
            if(l2!=null){
                res+=l2.val;
                l2 = l2.next;
            }
            if(ans==null){ //To create first ListNode for the answer
                ans = new ListNode(res%10);
                node = ans;
            }else{
                node.next = new ListNode(res%10);
                System.out.println(res%10);
                node = node.next;
            }
            carry = res/10;
        }
        //If there is a carry remaining, add it as the final node
        if(carry>0){
            node.next = new ListNode(carry);
        }
        return ans;
    }
}