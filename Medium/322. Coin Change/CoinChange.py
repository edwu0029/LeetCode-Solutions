'''
LeetCode Medium: 322. Coin Change
https://leetcode.com/problems/coin-change/description/

Check CoinChange.cpp for brief solution explanation.
'''
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        N = len(coins)
        dp = [-1 for i in range(amount+1)]
        dp[0] = 0
        for i in coins:
            for j in range(amount+1):
                if dp[j]==-1 or j+i>amount:
                    continue
                if dp[j+i]==-1:
                    dp[j+i] = dp[j]+1
                else:
                    dp[j+i] = min(dp[j+i], dp[j]+1)
        return dp[amount]