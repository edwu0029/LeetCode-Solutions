'''
LeetCode Medium: 430. Flatten a Multilevel Doubly Linked List
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

Check FlattenAMultilevelDoublyLinkedList.cpp for brief solution explanation.
'''
class Solution:
    def traverse(self, head, ans):
        if head==None:
            return
        ans.append(head.val)
        self.traverse(head.child, ans)
        self.traverse(head.next, ans)

    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head==None:
            return None
        ans = []
        self.traverse(head, ans)
        root = Node()
        cur = root
        prev = None
        for i in range(len(ans)):
            cur.val = ans[i]
            cur.prev = prev
            if i!=len(ans)-1:
                cur.next = Node()
            cur.child = None
            prev = cur
            cur = cur.next
        return root