/*
LeetCode Easy: 496. Next Greater Element I
https://leetcode.com/problems/next-greater-element-i/

Check NextGreaterElementI.cpp for brief solution explanation.
*/
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int N = nums2.length, M = nums1.length;
        Stack<Integer>stk = new Stack<Integer>();
        HashMap<Integer, Integer>m = new HashMap<Integer, Integer>();
        for(int i = 0;i<N;i++){
            while(!stk.empty()&&stk.peek()<nums2[i]){
                m.put(stk.peek(), nums2[i]);
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        int[]ans = new int[M];
        for(int i = 0;i<M;i++){
            ans[i] = m.getOrDefault(nums1[i], -1);
        }
        return ans;
    }
}