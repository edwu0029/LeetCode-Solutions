/*
LeetCode Hard: 312. Burst Balloons
https://leetcode.com/problems/burst-balloons/

Check BurstBalloons.cpp for brief solution explanation.
*/
class Solution {
    public int maxCoins(int[] nums) {
        int N = nums.length;
        ArrayList<Integer>vals = new ArrayList<Integer>();
        vals.add(1);
        for(int i:nums){
            vals.add(i);
        
        vals.add(1);
        int[][]dp = new int[N+1][N+1];
        for(int len = 1;len<=N;len++){
            for(int l = 1;l<=N-len+1;l++){
                int r = l+len-1;
                for(int m = l;m<=r;m++){
                    int res = vals.get(l-1)*vals.get(m)*vals.get(r+1);
                    if(l<=m-1){
                        res+=dp[l][m-1];
                    }
                    if(m+1<=r){
                        res+=dp[m+1][r];
                    }
                    dp[l][r] = Math.max(dp[l][r], res);
                }
            }
        }
        return dp[1][N];
    }
}