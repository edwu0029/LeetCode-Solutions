'''
LeetCode Medium: 279. Perfect Squares
https://leetcode.com/problems/perfect-squares/

Check PerfectSquares.cpp for brief solution explanation.
'''
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [0x3f3f3f3f for i in range(n+1)]
        dp[0] = 0
        for i in range(int(sqrt(n))+1):
            for j in range(n+1):
                if j+i*i<=n:
                    dp[j+i*i] = min(dp[j+i*i], dp[j]+1)
        return dp[n]