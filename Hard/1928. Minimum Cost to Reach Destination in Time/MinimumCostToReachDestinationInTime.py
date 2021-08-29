'''
LeetCode Hard: 1928. Minimum Cost to Reach Destination in Time
https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/

Check MinimumCostToReachDestinationInTime.cpp for brief solution explanation.
'''
class Solution:
    def minCost(self, maxTime: int, edges: List[List[int]], passingFees: List[int]) -> int:
        N = len(passingFees)
        adj = [[] for i in range(N)]
        for i in range(len(edges)):
            a, b, t = edges[i][0], edges[i][1], edges[i][2]
            adj[a].append((b, t))
            adj[b].append((a, t))
        dp = [[0x3f3f3f3f for i in range(N)] for i in range(maxTime+1)]
        dp[0][0] = passingFees[0]
        for i in range(maxTime):
            for j in range(N):
                if dp[i][j]>=0x3f3f3f3f:
                    continue
                for e in adj[j]:
                    v, newTime = e[0], i+e[1]
                    if newTime<=maxTime:
                        dp[newTime][v] = min(dp[newTime][v], dp[i][j]+passingFees[v])
        ans = 0x3f3f3f3f
        for i in range(maxTime+1):
            ans = min(ans, dp[i][N-1])
        if ans>=0x3f3f3f3f:
            return -1
        else:
            return ans