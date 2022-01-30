/*
LeetCode Medium: 430. Flatten a Multilevel Doubly Linked List
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

Check FlattenAMultilevelDoublyLinkedList.cpp for brief solution explanation.
*/
class Solution {
    public void traverse(Node head, ArrayList<Integer>ans){
        if(head==null){
            return;
        }
        ans.add(head.val);
        traverse(head.child, ans);
        traverse(head.next, ans);
    }
    public Node flatten(Node head) {
        if(head==null){
            return null;
        }
        ArrayList<Integer>ans = new ArrayList<Integer>();
        traverse(head, ans);
        Node root = new Node();
        Node cur = root;
        Node prev = null;
        for(int i = 0;i<ans.size();i++){
            cur.val = ans.get(i);
            cur.prev = prev;
            if(i!=ans.size()-1){
                cur.next = new Node();
            }
            cur.child = null;
            prev = cur;
            cur = cur.next;
        }
        return root;
    }
}