/*
LeetCode Hard: 123. Best Time to Buy and Sell Stock III
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Check BestTimeToBuyAndSellStockIII.cpp for brief solution explanation.
*/
class Solution {
    public int maxProfit(int[] prices) {
        int N = prices.length;
        int[][]dp = {{-0x3f3f3f3f, 0, -0x3f3f3f3f, 0}, {0, 0, 0, 0}};
        int pre = 0, cur = 1;
        for(int i = 0;i<N;i++){
            dp[cur][0] = Math.max(dp[pre][0], -prices[i]);
            dp[cur][1] = Math.max(dp[pre][1], dp[pre][0]+prices[i]);
            dp[cur][2] = Math.max(dp[pre][2], dp[pre][1]-prices[i]);
            dp[cur][3] = Math.max(dp[pre][3], dp[pre][2]+prices[i]);
            int t = pre;
            pre = cur;
            cur = t;
        }
        return Math.max(0, Math.max(dp[pre][1], dp[pre][3]));
    }
}