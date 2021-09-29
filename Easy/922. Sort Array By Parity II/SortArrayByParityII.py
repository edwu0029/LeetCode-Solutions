'''
LeetCode Easy: 922. Sort Array By Parity II
https://leetcode.com/problems/sort-array-by-parity-ii/

Check SortArrayByParityII.cpp for brief solution explanation.
'''
class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        N = len(nums)
        i, j = 0, 1
        while i<N and j<N:
            while i<N and nums[i]%2==0:
                i+=2
            while j<N and nums[j]%2==1:
                j+=2
            if i<N and j<N:
                nums[i], nums[j] = nums[j], nums[i]
            elif i>=N or j>=N:
                break
        return nums