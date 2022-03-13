'''
LeetCode Hard: 123. Best Time to Buy and Sell Stock III
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Check BestTimeToBuyAndSellStockIII.cpp for brief solution explanation.
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = len(prices)
        dp = [[-0x3f3f3f3f, 0, -0x3f3f3f3f, 0], [0, 0, 0, 0]]
        pre, cur = 0, 1
        for i in range(N):
            dp[cur][0] = max(dp[pre][0], -prices[i])
            dp[cur][1] = max(dp[pre][1], dp[pre][0]+prices[i])
            dp[cur][2] = max(dp[pre][2], dp[pre][1]-prices[i])
            dp[cur][3] = max(dp[pre][3], dp[pre][2]+prices[i])
            pre, cur = cur, pre
        return max(0, max(dp[pre][1], dp[pre][3]))