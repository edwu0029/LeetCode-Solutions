/*
LeetCode Medium: 309. Best Time to Buy and Sell Stock with Cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Check BestTimeToBuyAndSellStockWithCooldown.cpp for brief solution explanation.
*/
class Solution {
    public int maxProfit(int[] prices) {
        int N = prices.length;
        if(N==1){
            return 0;
        }
        int[]buy = new int[N], sell = new int[N];
        buy[0] = -prices[0];
        buy[1] = Math.max(-prices[0], -prices[1]);
        sell[1] = Math.max(0, prices[1]-prices[0]);
        for(int i = 2;i<N;i++){
            buy[i] = Math.max(buy[i-1], sell[i-2]-prices[i]);
            sell[i] = Math.max(sell[i-1], buy[i-1]+prices[i]);
        }
        return sell[N-1];
    }
}