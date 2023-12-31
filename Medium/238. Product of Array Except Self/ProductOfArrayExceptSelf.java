/*
LeetCode Medium: 238. Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/description/

Check ProductOfArrayExceptSelf.cpp for brief solution explanation.
*/
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int N = nums.length;
        int[]prefix = new int[N];
        int[]suffix = new int[N];
        prefix[0] = nums[0];
        suffix[N-1] = nums[N-1];
        for(int i = 1;i<N;i++){
            prefix[i] = prefix[i-1]*nums[i];
            suffix[N-1-i] = suffix[N-i]*nums[N-1-i];
        }
        int[]ans = new int[N];
        ans[0] = suffix[1];
        ans[N-1] = prefix[N-2];
        for(int i = 1;i<N-1;i++){
            ans[i] = prefix[i-1]*suffix[i+1];
        }
        return ans;
    }
}