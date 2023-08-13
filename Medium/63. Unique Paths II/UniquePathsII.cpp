/*
LeetCode Medium: 63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/description/

Brief Solution Explanation:
M = Rows in obstacleGrid
N = Columns in obstacleGrid
- We can use a simple dp top to bottom technique to find the number of unique paths
- Firstly, we must consider the corner case of if there are obstacles at either (0, 0) or (M-1, N-1),
  which would result in 0 unique paths
    - This would make it impossible to start the robot, or get to the final destination
- Let dp[i][j] be the number of unique ways to get from (0, 0) to (i, j)
    - Since the robot can only move down and right, we know that we can move to (i, j) by:
        - Moving right from (i-1, j)
        - Moving down from (i, j-1)
    - Therefore dp[i][j] = dp[i-1][j]+dp[i][j-1]
        - Given that (i-1, j) and (i, j-1) are both valid points
        - Here, a point (a, b) would be valid if it is in range for the grid AND (a, b) doesn't have a obstacle
        - If a point (x, y) is NOT a valid point, we can assume dp[x][y] = 0, since it is impossible to reach a point
        where there is a obstacle
- We can start with dp[0][0] = 1, only one way to start
    - We can generate all dp[i][j] by looping for all i in 0 to M, all j in 0 to N
    - We must generate in this order since dp[i][j] requires us to process dp[i-1][j] and dp[i][j-1] first
- Our final answer would be dp[M-1][N-1], which we can return

Time Complexity: O(N*M)
Memory Complexity: O(N*M)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        //Check corner case of only one square, which has a obstacle
        if(obstacleGrid[0][0]==1||obstacleGrid[M-1][N-1]==1){
            return 0;
        }
        vector<vector<int>>dp(M, vector<int>(N, 0));
        dp[0][0] = 1;
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                int t = 0;
                //If can reach (i, j) by moving right
                if(i-1>=0&&obstacleGrid[i-1][j]==0) t+=dp[i-1][j];
                //If can reach (i, j) by moving down
                if(j-1>=0&&obstacleGrid[i][j-1]==0) t+=dp[i][j-1];
                dp[i][j]+=t;
            }
        }
        return dp[M-1][N-1];
    }
};
