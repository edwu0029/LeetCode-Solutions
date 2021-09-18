'''
LeetCode Medium: 978. Longest Turbulent Subarray
https://leetcode.com/problems/longest-turbulent-subarray/

Check LongestTurbulentSubarray.cpp for brief solution explanation.
'''
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        N = len(arr)
        ans, inc, dec = 1, 1, 1
        for i in range(1, N):
            if arr[i-1]==arr[i]:
                inc, dec = 1, 1
            elif arr[i-1]>arr[i]:
                dec = inc+1
                inc = 1
            else:
                inc = dec+1
                dec = 1
            ans = max(ans, max(inc, dec))
        return ans