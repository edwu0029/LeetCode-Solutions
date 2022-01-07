'''
LeetCode Medium: 382. Linked List Random Node
https://leetcode.com/problems/linked-list-random-node/

Check LinkedListRandomNode.cpp for brief solution explanation.
'''
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.arr = []
        while head is not None:
            self.arr.append(head.val)
            head = head.next

    def getRandom(self) -> int:
        return self.arr[randint(0, len(self.arr)-1)]