'''
LeetCode Medium: 309. Best Time to Buy and Sell Stock with Cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Check BestTimeToBuyAndSellStockWithCooldown.cpp for brief solution explanation.
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = len(prices)
        if N==1:
            return 0
        buy, sell = [0 for i in range(N)], [0 for i in range(N)]
        buy[0] = -prices[0]
        buy[1] = max(-prices[0], -prices[1])
        sell[1] = max(0, prices[1]-prices[0])
        for i in range(2, N):
            buy[i] = max(buy[i-1], sell[i-2]-prices[i])
            sell[i] = max(sell[i-1], buy[i-1]+prices[i])
        return sell[-1]