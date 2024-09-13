'''
LeetCode Medium: 518. Coin Change II
https://leetcode.com/problems/coin-change-ii/

Check CoinChangeIi.cpp for brief solution explanation.
'''
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        N = len(coins)
        dp = [0 for i in range(amount+1)]
        dp[0] = 1
        for c in coins:
            for i in range(amount):
                if i+c>amount:
                    continue
                dp[i+c]+=dp[i]
        return dp[amount]
        