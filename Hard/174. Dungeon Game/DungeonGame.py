'''
LeetCode Hard: 174. Dungeon Game
https://leetcode.com/problems/dungeon-game/

Check DungeonGame.cpp for brief solution explanation.
'''
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        M, N = len(dungeon), len(dungeon[0])
        dp = [[0 for i in range(N)] for i in range(M)]
        if dungeon[M-1][N-1]>=0:
            dp[M-1][N-1] = 1
        else:
            dp[M-1][N-1] = -dungeon[M-1][N-1]+1
        def bounds(r, c):
            return 0<=r<M and 0<=c<N
        
        for i in range(M-1, -1, -1):
            for j in range(N-1, -1, -1):
                if i==M-1 and j==N-1:
                    continue
                t = 0x3f3f3f3f;
                if bounds(i+1, j):
                    t = min(t, dp[i+1][j])
                if bounds(i, j+1):
                    t = min(t, dp[i][j+1])
                dp[i][j] = max(t-dungeon[i][j], 1)
        return dp[0][0]