'''
LeetCode Medium: 15. 3Sum
https://leetcode.com/problems/3sum/

Check 3Sum.cpp for brief solution explanation.
'''
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        N = len(nums)
        nums.sort()
        ans = []
        for l in range(N-2):
            if l>0 and nums[l-1]==nums[l]:
                continue
            m, r = l+1, N-1
            while m<r and m<N and r<N:
                cur_sum = nums[m]+nums[r]
                if cur_sum<-nums[l]:
                    m+=1
                elif cur_sum>-nums[l]:
                    r-=1
                else:
                    t = [nums[l], nums[m], nums[r]]
                    ans.append(t)
                    while m<r and nums[m]==t[1]:
                        m+=1
                    while m<r and nums[r]==t[2]:
                        r-=1
        return ans