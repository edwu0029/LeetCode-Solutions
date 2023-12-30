'''
LeetCode Easy: 217. Contains Duplicate
https://leetcode.com/problems/contains-duplicate/

Check ContainsDuplicate.cpp for brief solution explanation.
'''
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        N = len(nums)
        freq = {}
        for i in range(N):
            if(nums[i] not in freq):
                freq[nums[i]] = True
            else:
                return True
        return False
