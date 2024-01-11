'''
LeetCode Medium: 200. Number of Islands
https://leetcode.com/problems/number-of-islands/description/

Check NumberOfIslands.cpp for brief solution explanation.
'''
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        M = len(grid)
        N = len(grid[0])
        groups = [[0 for i in range(N)] for i in range(M)]
        g = 0
        x = [0, 0, 1, -1]
        y = [1, -1, 0, 0]
        def dfs(r, c, group):
            groups[r][c] = group
            for i in range(4):
                nxtr = r+x[i]
                nxtc = c+y[i]
                check = nxtr<M and nxtc<N and 0<=nxtr and 0<=nxtc
                if check and groups[nxtr][nxtc]==0 and grid[nxtr][nxtc]=='1':
                    dfs(nxtr, nxtc, group)

        for i in range(M):
            for j in range(N):
                if groups[i][j]!=0:
                    continue
                if groups[i][j]==0 and grid[i][j]=='1':
                    g+=1
                    dfs(i, j, g)
        return g