'''
LeetCode Easy: 922. Sort Array By Parity II
https://leetcode.com/problems/sort-array-by-parity-ii/

Check SortArrayByParityII.cpp for brief solution explanation.
'''
class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        N = len(nums)
        evens, odds = [], []
        for i in range(N):
            if nums[i]%2==0:
                evens.append(nums[i])
            else:
                odds.append(nums[i])
        ans = []
        p1, p2 = 0, 0
        for i in range(N):
            if i%2==0:
                ans.append(evens[p1])
                p1+=1
            else:
                ans.append(odds[p2])
                p2+=1
        return ans