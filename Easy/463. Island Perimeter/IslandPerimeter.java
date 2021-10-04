/*
LeetCode Easy: 463. Island Perimeter
https://leetcode.com/problems/island-perimeter/

Check IslandPerimeter.cpp for brief solution explanation.
*/
class Solution {
    public boolean bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    public int islandPerimeter(int[][] grid) {
        int M = grid.length, N = grid[0].length;
        int[][]neighbours = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int perimeter = 0;
        for(int r = 0;r<M;r++){
            for(int c = 0;c<N;c++){
                if(grid[r][c]==0){
                    continue;
                }
                for(int k = 0;k<4;k++){
                    int newR = r+neighbours[k][0], newC = c+neighbours[k][1];
                    if(!bounds(newR, newC, M, N)||grid[newR][newC]==0){
                        perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
}