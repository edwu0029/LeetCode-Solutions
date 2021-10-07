'''
LeetCode Medium: 442. Find All Duplicates in an Array
https://leetcode.com/problems/find-all-duplicates-in-an-array/

Check FindAllDuplicatesInAnArray.cpp for brief solution explanation.
'''
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        N = len(nums)
        ans = []
        for i in range(N):
            cur = abs(nums[i])
            if nums[cur-1]<0:
                ans.append(cur)
            else:
                nums[cur-1]*=-1
        return ans