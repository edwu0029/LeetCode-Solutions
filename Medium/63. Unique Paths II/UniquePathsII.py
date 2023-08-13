'''
LeetCode Medium: 63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/description/

Check UniquePathsII.cpp for brief solution explanation.
'''
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        M, N = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0]==1 or obstacleGrid[M-1][N-1]==1:
            return 0
        dp = [[0 for j in range(N)] for i in range(M)]
        dp[0][0] = 1
        for i in range(M):
            for j in range(N):
                t = 0
                if i-1>=0 and obstacleGrid[i-1][j]==0:
                    t+=dp[i-1][j]
                if j-1>=0 and obstacleGrid[i][j-1]==0:
                    t+=dp[i][j-1]
                dp[i][j]+=t
        return dp[M-1][N-1]