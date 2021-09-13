/*
LeetCode Easy: 1991. Find the Middle Index in Array
https://leetcode.com/problems/find-the-middle-index-in-array/

Check FindTheMiddleIndexInArray.cpp for brief solution explanation.
*/
class Solution {
    public int findMiddleIndex(int[] nums) {
        int N = nums.length;
        int[]prefix = new int[N+1];
        for(int i = 0;i<N;i++){
            prefix[i+1] = nums[i]+prefix[i];
        }
        for(int i = 1;i<=N;i++){
            int lft = prefix[i-1]-prefix[0];
            int rht = prefix[N]-prefix[i];
            if(lft==rht){
                return i-1;
            }
        }
        return -1;
    }
}