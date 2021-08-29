'''
LeetCode Easy: 1984. Minimum Difference Between Highest and Lowest of K Scores
https://leetcode.com/problems/roman-to-integer/

Check Minimum DifferenceBetweenHighestAndLowestOfKScores.cpp for brief solution explanation.
'''
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        N = len(nums)
        if N==0:
            return 0
        nums.sort()
        ans = nums[N-1]
        for i in range(N-k+1):
            ans = min(ans, nums[i+k-1]-nums[i])
        return ans