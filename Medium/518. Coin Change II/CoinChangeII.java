/*
LeetCode Medium: 518. Coin Change II
https://leetcode.com/problems/coin-change-ii/

Check CoinChangeIi.cpp for brief solution explanation.
*/
class Solution {
    public int change(int amount, int[] coins) {
        int N = coins.length;
        int[]dp = new int[amount+1];
        dp[0] = 1;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<amount;j++){
                if(j+coins[i]>amount) continue;
                dp[j+coins[i]]+=dp[j];
            }
        }
        return dp[amount];
    }
}