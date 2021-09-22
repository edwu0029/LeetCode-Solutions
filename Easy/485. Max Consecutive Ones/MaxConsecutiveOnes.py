'''
LeetCode Easy: 485. Max Consecutive Ones
https://leetcode.com/problems/max-consecutive-ones/

Check MaxConsecutiveOnes.cpp for brief solution explanation.
'''
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        N = len(nums)
        ans, cnt = 0, 0
        for i in range(N):
            if nums[i]==1:
                cnt+=1
                ans = max(ans, cnt)
            else:
                cnt = 0
        return ans