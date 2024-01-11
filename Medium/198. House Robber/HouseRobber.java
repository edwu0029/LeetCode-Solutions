/*
LeetCode Medium: 198. House Robber
https://leetcode.com/problems/house-robber/description/

Check HouseRobber.cpp for brief solution explanation.
*/
class Solution {
    public int rob(int[] nums) {
        int N = nums.length;
        int[]dp = new int[N+1];
        dp[1] = nums[0];
        for(int i = 2;i<=N;i++){
            dp[i] = Math.max(dp[i-1], nums[i-1]+dp[i-2]);
        }
        return dp[N];
    }
}