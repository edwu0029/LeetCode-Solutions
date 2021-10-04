'''
LeetCode Easy: 463. Island Perimeter
https://leetcode.com/problems/island-perimeter/

Check IslandPerimeter.cpp for brief solution explanation.
'''
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])
        neighbours = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        perimeter = 0
        def bounds(r, c) -> bool:
            return 0<=r<M and 0<=c<N
        
        for r in range(M):
            for c in range(N):
                if grid[r][c]==0:
                    continue
                for k in range(4):
                    newR, newC = r+neighbours[k][0], c+neighbours[k][1]
                    if not bounds(newR, newC) or grid[newR][newC]==0:
                        perimeter+=1
        return perimeter