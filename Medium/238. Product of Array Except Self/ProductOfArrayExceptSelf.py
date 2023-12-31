'''
LeetCode Medium: 238. Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/description/

Check ProductOfArrayExceptSelf.cpp for brief solution explanation.
'''
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        N = len(nums)
        prefix = [nums[i] for i in range(N)]
        suffix = [nums[i] for i in range(N)]
        ans = [0 for i in range(N)]
        for i in range(1, N):
            prefix[i]*=prefix[i-1]
            suffix[N-i-1]*=suffix[N-i]
        ans[0] = suffix[1]
        ans[N-1] = prefix[N-2]
        for i in range(1, N-1):
            ans[i] = prefix[i-1]*suffix[i+1]
        return ans