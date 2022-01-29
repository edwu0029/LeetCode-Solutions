'''
LeetCode Hard: 312. Burst Balloons
https://leetcode.com/problems/burst-balloons/

Check BurstBalloons.cpp for brief solution explanation.
'''
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        N = len(nums)
        nums.insert(N, 1)
        nums.insert(0, 1)
        dp = [[0 for i in range(N+1)] for i in range(N+1)]
        for sz in range(1, N+1):
            for l in range(1, N-sz+2):
                r = l+sz-1
                for m in range(l, r+1):
                    res = nums[l-1]*nums[m]*nums[r+1]
                    if l<=m-1:
                        res+=dp[l][m-1]
                    if m+1<=r:
                        res+=dp[m+1][r]
                    dp[l][r] = max(dp[l][r], res)
        return dp[1][N]
