'''
LeetCode Medium: 2352. Equal Row and Column Pairs
https://leetcode.com/problems/equal-row-and-column-pairs/

Check EqualRowAndColumnPairs.cpp for brief solution explanation.
'''
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        N = len(grid)
        SEED, MOD = 131, int(1e9+7)
        row_hash = [0 for i in range(N)]
        for r in range(N):
            for i in range(N):
                row_hash[r] = ((row_hash[r]*SEED)%MOD+grid[r][i])%MOD
        col_hash = [0 for i in range(N)]
        for c in range(N):
            for i in range(N):
                col_hash[c] = ((col_hash[c]*SEED)%MOD+grid[i][c])%MOD
        ans = 0
        for r in range(N):
            for c in range(N):
                if row_hash[r]==col_hash[c]:
                    ans+=1
        return ans