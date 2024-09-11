/*
LeetCode Medium: 322. Coin Change
https://leetcode.com/problems/coin-change/description/

Check CoinChange.cpp for brief solution explanation.
*/
class Solution {
    public int coinChange(int[] coins, int amount) {
        int N = coins.length;
        int[]dp = new int[amount+1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<=amount;j++){
                if(dp[j]==-1 || (long)j+coins[i]>(long)amount) continue;
                if(dp[j+coins[i]]==-1) dp[j+coins[i]] = dp[j]+1;
                else dp[j+coins[i]] = Math.min(dp[j+coins[i]], dp[j]+1);
            }
        }
        return dp[amount];
    }
}