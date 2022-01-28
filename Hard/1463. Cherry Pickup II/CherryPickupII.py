'''
LeetCode Hard: 1463. Cherry Pickup II
https://leetcode.com/problems/cherry-pickup-ii/

Check CherryPickupII.cpp for brief solution explanation.
'''
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])
        dp = [[[-1e9 for i in range(N)] for i in range(N)] for i in range(M)]
        adj = [-1, 0, 1]
        dp[0][0][N-1] = grid[0][0]+grid[0][N-1]
        for i in range(M-1):
            for c1 in range(N):
                for c2 in range(N):
                    for dc1 in adj:
                        for dc2 in adj:
                            nc1, nc2 = c1+dc1, c2+dc2
                            if not(0<=nc1<N and 0<=nc2<N):
                                continue
                            if nc1==nc2:
                                t = dp[i][c1][c2]+grid[i+1][nc2]
                                dp[i+1][nc1][nc2] = max(dp[i+1][nc1][nc2], t)
                            else:
                                t = dp[i][c1][c2]+grid[i+1][nc1]+grid[i+1][nc2]
                                dp[i+1][nc1][nc2] = max(dp[i+1][nc1][nc2], t)
        ans = 0
        for i in range(N):
            for j in range(N):
                ans = max(ans, dp[M-1][i][j])
        return ans