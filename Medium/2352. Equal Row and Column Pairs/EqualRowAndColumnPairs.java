/*
LeetCode Medium: 2352. Equal Row and Column Pairs
https://leetcode.com/problems/equal-row-and-column-pairs/

Check EqualRowAndColumnPairs.cpp for brief solution explanation.
*/
class Solution {
    public int equalPairs(int[][] grid) {
        int N = grid.length;
        int SEED = 131, MOD = (int)1e9+7;
        long[]row_hash = new long[N];
        for(int r = 0;r<N;r++){
            for(int i = 0;i<N;i++){
                row_hash[r] = ((row_hash[r]*SEED)%MOD+grid[r][i])%MOD;
            }
        }
        long[]col_hash = new long[N];
        for(int c = 0;c<N;c++){
            for(int i = 0;i<N;i++){
                col_hash[c] = ((col_hash[c]*SEED)%MOD+grid[i][c])%MOD;
            }
        }
        int ans = 0;
        for(int r = 0;r<N;r++){
            for(int c = 0;c<N;c++){
                if(row_hash[r]==col_hash[c]){
                    ans++;
                }
            }
        }
        return ans;
    }
}