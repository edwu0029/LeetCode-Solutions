'''
LeetCode Medium: 2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/

Check AddTwoNumbers.cpp for brief solution explanation.
'''
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ans, node = None, None
        carry = 0
        while l1!=None or l2!=None:
            res = carry
            if l1!=None:
                res+=l1.val
                l1 = l1.next
            if l2!=None:
                res+=l2.val
                l2 = l2.next
            if ans==None:
                ans = ListNode(res%10)
                node = ans
            else:
                node.next = ListNode(res%10)
                node = node.next
            carry = res//10
        if carry>0:
            node.next = ListNode(carry)
        return ans

