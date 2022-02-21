'''
LeetCode Easy: 169. Majority Element
https://leetcode.com/problems/majority-element/

Check MajorityElement.cpp for brief solution explanation.
'''
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        N = len(nums)
        freq = {}
        ans = 0
        for i in range(N):
            if nums[i] not in freq:
                freq[nums[i]] = 1
            else:
                freq[nums[i]]+=1
            if freq[nums[i]]>N//2:
                ans = nums[i]
                break
        return ans