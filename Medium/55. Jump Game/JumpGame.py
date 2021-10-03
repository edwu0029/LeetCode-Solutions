'''
LeetCode Medium: 55. Jump Game
https://leetcode.com/problems/jump-game/

Check JumpGame.cpp for brief solution explanation.
'''
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        N = len(nums)
        mx_reachable = 0
        for i in range(N):
            if mx_reachable<i:
                return False
            else:
                mx_reachable = max(mx_reachable, i+nums[i])
        return True