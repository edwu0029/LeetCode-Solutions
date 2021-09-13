'''
LeetCode Easy: 1991. Find the Middle Index in Array
https://leetcode.com/problems/find-the-middle-index-in-array/

Check FindTheMiddleIndexInArray.cpp for brief solution explanation.
'''
class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        N = len(nums)
        prefix = [0 for i in range(N+1)]
        for i in range(N):
            prefix[i+1] = nums[i]+prefix[i]
        for i in range(1, N+1):
            lft = prefix[i-1]-prefix[0]
            rht = prefix[N]-prefix[i]
            if lft==rht:
                return i-1
        return -1