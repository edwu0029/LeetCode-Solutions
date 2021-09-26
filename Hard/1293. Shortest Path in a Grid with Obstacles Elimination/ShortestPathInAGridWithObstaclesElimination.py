'''
LeetCode Hard: 1293. Shortest Path in a Grid with Obstacles Elimination
https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

Check ShortestPathInAGridWithObstaclesElimination.cpp for brief solution explanation.
'''
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        M, N = len(grid), len(grid[0])
        def bounds(r, c) -> bool:
            return 0<=r<M and 0<=c<N
        dis = [[[0 for i in range(k+1)]for i in range(N)]for i in range(M)]
        vis = [[[False for i in range(k+1)]for i in range(N)]for i in range(M)]
        dis[0][0][0] = 0
        vis[0][0][0] = True
        moves = [[0, -1], [0, 1], [-1, 0], [1, 0]] #Up, Down, Left, Right
        q = deque([[0, 0, 0]])
        while len(q)>0:
            cur = q.popleft()
            r, c, z = cur[0], cur[1], cur[2]
            if r==M-1 and c==N-1:
                return dis[r][c][z]
            for i in range(4):
                newR, newC = r+moves[i][0], c+moves[i][1]
                if bounds(newR, newC):
                    if grid[newR][newC]==1 and z<k and not vis[newR][newC][z+1]:
                        dis[newR][newC][z+1] = dis[r][c][z]+1
                        vis[newR][newC][z+1] = True
                        q.append([newR, newC, z+1])
                    if grid[newR][newC]==0 and not vis[newR][newC][z]:
                        dis[newR][newC][z] = dis[r][c][z]+1
                        vis[newR][newC][z] = True
                        q.append([newR, newC, z])
        return -1