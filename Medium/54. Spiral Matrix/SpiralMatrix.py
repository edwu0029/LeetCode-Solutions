'''
LeetCode Medium: 54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/

Check SpiralMatrix.cpp for brief solution explanation.
'''
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        M, N = len(matrix), len(matrix[0])
        vis = [[False for i in range(N)] for i in range(M)]
        ans = [matrix[0][0]]
        r, c = 0, 0
        vis[0][0] = True
        while len(ans)!=M*N:
            while c+1<N and not vis[r][c+1]:
                vis[r][c+1] = True
                ans.append(matrix[r][c+1])
                c+=1
            while r+1<M and not vis[r+1][c]:
                vis[r+1][c] = True
                ans.append(matrix[r+1][c])
                r+=1
            while c-1>=0 and not vis[r][c-1]:
                vis[r][c-1] = True
                ans.append(matrix[r][c-1])
                c-=1
            while r-1>=0 and not vis[r-1][c]:
                vis[r-1][c] = True
                ans.append(matrix[r-1][c])
                r-=1
        return ans