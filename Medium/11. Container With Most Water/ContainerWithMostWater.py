'''
LeetCode Medium: 11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/description/

Check ContainerWithMostWater.cpp for brief solution explanation.
'''
class Solution:
    def maxArea(self, height: List[int]) -> int:
        N = len(height)
        ans, l, r = 0, 0, N-1
        while l<=r:
            ans = max(ans, min(height[l], height[r])*(r-l))
            if height[l]<height[r]:
                l+=1
            else:
                r-=1
        return ans