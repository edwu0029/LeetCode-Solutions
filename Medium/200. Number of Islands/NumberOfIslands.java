/*
LeetCode Medium: 200. Number of Islands
https://leetcode.com/problems/number-of-islands/description/

Check NumberOfIslands.cpp for brief solution explanation.
*/
class Solution {
    public int numIslands(char[][] grid) {
        int M = grid.length, N = grid[0].length;
        int[][]groups = new int[M][N];
        int g = 0;
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(groups[i][j]!=0) continue;
                if(groups[i][j]==0&&grid[i][j]=='1'){
                    //Found ungrouped land
                    g++;
                    dfs(grid, groups, i, j, g, M, N);
                }
            }
        }
        return g;
    }
    void dfs(char[][]grid, int[][]groups, int r, int c, int group, int M, int N){
        groups[r][c] = group;
        int[]x = {0, 0, -1, 1};
        int[]y = {1, -1, 0, 0};
        for(int i = 0;i<4;i++){
            int nxtr = r+x[i];
            int nxtc = c+y[i];
            boolean check = nxtr<M&&nxtc<N&&0<=nxtr&&0<=nxtc;
            if(check&&groups[nxtr][nxtc]==0&&grid[nxtr][nxtc]=='1'){
                dfs(grid, groups, nxtr, nxtc, group, M, N);
            }
        }
    }
}