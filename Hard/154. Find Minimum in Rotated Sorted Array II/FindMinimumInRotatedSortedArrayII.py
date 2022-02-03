'''
LeetCode Hard: 154. Find Minimum in Rotated Sorted Array II
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Check FindMinimumInRotatedSortedArrayII.cpp for brief solution explanation.
'''
class Solution:
    def findMin(self, nums: List[int]) -> int:
        N = len(nums)
        l, r = 0, N-1
        while l<r:
            m = (l+r)//2
            if nums[m]>nums[r]:
                l = m+1
            elif nums[m]<nums[r]:
                r = m
            else:
                r-=1
        return nums[l]