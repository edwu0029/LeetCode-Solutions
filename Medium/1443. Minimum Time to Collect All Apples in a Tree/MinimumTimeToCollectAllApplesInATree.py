'''
LeetCode Medium: 1443. Minimum Time to Collect All Apples in a Tree
https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

Check MinimumTimeToCollectAllApplesInATree.cpp for brief solution explanation.
'''
class Solution:
    def minTime(self, N: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = [[] for i in range(N)]
        subtreeHasApples = [False for i in range(N)]
        vis = [False for i in range(N)]
        sum = [0 for i in range(N)]
        for i in range(len(edges)):
            adj[edges[i][0]].append(edges[i][1])
            adj[edges[i][1]].append(edges[i][0])
        def dfs(u):
            vis[u] = True
            if hasApple[u]==True:
                subtreeHasApples[u] = True
            for nxt in adj[u]:
                if not vis[nxt]:
                    t = dfs(nxt)
                    if t:
                        sum[u]+=2+sum[nxt]
                    subtreeHasApples[u] = subtreeHasApples[u] or t
            return subtreeHasApples[u]
        dfs(0)
        return sum[0]