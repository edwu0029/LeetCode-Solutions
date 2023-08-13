/*
LeetCode Medium: 63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/description/

Check UniquePathsII.cpp for brief solution explanation.
*/
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int M = obstacleGrid.length, N = obstacleGrid[0].length;
        if(obstacleGrid[0][0]==1||obstacleGrid[M-1][N-1]==1){
            return 0;
        }
        int[][]dp = new int[M][N];
        dp[0][0] = 1;
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                int t = 0;
                if(i-1>=0&&obstacleGrid[i-1][j]==0) t+=dp[i-1][j];
                if(j-1>=0&&obstacleGrid[i][j-1]==0) t+=dp[i][j-1];
                dp[i][j]+=t;
            }
        }
        return dp[M-1][N-1];
    }
}