'''
LeetCode Medium: 198. House Robber
https://leetcode.com/problems/house-robber/description/

Check HouseRobber.cpp for brief solution explanation.
'''
class Solution:
    def rob(self, nums: List[int]) -> int:
        N = len(nums)
        dp = [0 for i in range(N+1)]
        dp[1] = nums[0]
        for i in range(2, N+1):
            dp[i] = max(dp[i-1], nums[i-1]+dp[i-2])
        return dp[N]