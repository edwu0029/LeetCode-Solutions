'''
LeetCode Easy: 1. Two Sum
https://leetcode.com/problems/two-sum/

Check TwoSum.cpp for brief solution explanation.
'''
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i in range(len(nums)):
            m[nums[i]] = i
        for i in range(len(nums)):
            conjugate = target-nums[i]
            if conjugate in m and i!=m[conjugate]:
                ans = {i, m[conjugate]}
                break
        return ans