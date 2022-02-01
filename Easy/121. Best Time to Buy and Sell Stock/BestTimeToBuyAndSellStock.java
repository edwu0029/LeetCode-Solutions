/*
LeetCode Easy: 121. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Check BestTimeToBuyAndSellStock.cpp for brief solution explanation.
*/
class Solution {
    public int maxProfit(int[] prices) {
        int N = prices.length;
        int[]maxx = new int[N];
        maxx[N-1] = prices[N-1];
        for(int i = N-2;i>=0;i--){
            maxx[i] = Math.max(prices[i],maxx[i+1]);
        }
        int ans = 0;
        for(int i = 0;i<N-1;i++){
            ans = Math.max(ans, maxx[i+1]-prices[i]);
        }
        return ans;
    }
}