/*
LeetCode Medium: 382. Linked List Random Node
https://leetcode.com/problems/linked-list-random-node/

Check LinkedListRandomNode.cpp for brief solution explanation.
*/
class Solution {
    private ArrayList<Integer>arr;
    public Solution(ListNode head) {
        arr = new ArrayList<Integer>();
        while(head!=null){
            arr.add(head.val);
            head = head.next;
        }
    }
    
    public int getRandom() {
        return arr.get((int)(Math.random()*arr.size()));
    }
}