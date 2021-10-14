/*
LeetCode Medium: 279. Perfect Squares
https://leetcode.com/problems/perfect-squares/

Check PerfectSquares.cpp for brief solution explanation.
*/
class Solution {
    public int numSquares(int n) {
        int[]dp = new int[n+1];
        Arrays.fill(dp, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 1;i*i<=n;i++){
            for(int j = 0;j<=n;j++){
                if(j+i*i<=n){
                    dp[j+i*i] = Math.min(dp[j+i*i], dp[j]+1);
                }
            }
        }
        return dp[n];
    }
}