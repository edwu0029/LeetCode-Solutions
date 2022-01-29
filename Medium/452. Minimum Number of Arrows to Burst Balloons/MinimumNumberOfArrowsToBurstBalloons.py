'''
LeetCode Medium: 452. Minimum Number of Arrows to Burst Balloons
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

Check MinimumNumberOfArrowsToBurstBalloons.cpp for brief solution explanation.
'''
class Solution:
    def findMinArrowShots(self, points):
        points.sort(key = lambda x: x[1])
        N = len(points)
        if N==0:
            return 0
        ans = 0
        cur = points[0]
        for i in range(1, n):
            if cur[1]<points[i][0]:
                ans+=1
                cur = points[i]
        return ans