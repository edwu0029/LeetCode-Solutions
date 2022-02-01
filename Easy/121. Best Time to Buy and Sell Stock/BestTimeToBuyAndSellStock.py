'''
LeetCode Easy: 121. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Check BestTimeToBuyAndSellStock.cpp for brief solution explanation.
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = len(prices)
        maxx = [0 for i in range(N)]
        maxx[N-1] = prices[N-1]
        for i in range(N-2, -1, -1):
            maxx[i] = max(prices[i], maxx[i+1])
        ans = 0
        for i in range(N-1):
            ans = max(ans, maxx[i+1]-prices[i])
        return ans