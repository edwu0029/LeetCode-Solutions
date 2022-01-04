'''
LeetCode Medium: 994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/

Check RottingOranges.cpp for brief solution explanation.
'''
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])
        q = []
        vis = [[False for i in range(N)]for i in range(M)]
        time = [[0 for i in range(N)]for i in range(M)]
        cnt = 0
        for i in range(M):
            for j in range(N):
                if grid[i][j]==2:
                    q.append([i, j])
                    vis[i][j] = True
                elif grid[i][j]==1:
                    cnt+=1
        adj = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        ans = 0
        while len(q)>0:
            cur = q.pop(0)
            r, c = cur[0], cur[1]
            ans = time[r][c]
            for i in range(4):
                newR, newC = r+adj[i][0], c+adj[i][1]
                bounds = 0<=newR<M and 0<=newC<N
                if bounds and not vis[newR][newC] and grid[newR][newC]==1:
                    vis[newR][newC] = True
                    time[newR][newC] = time[r][c]+1
                    cnt-=1
                    q.append([newR, newC])
        if cnt==0:
            return ans
        else:
            return -1
            