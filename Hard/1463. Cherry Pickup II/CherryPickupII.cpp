/*
LeetCode Hard: 1463. Cherry Pickup II
https://leetcode.com/problems/cherry-pickup-ii/

Brief Solution Explanation:
M = Number of rows
N = Number of columns
- We can use a top down approach to do this problem
- Let dp[r][c1][c2] represent the maximum number of cherries that can be collected such that Robot #1 ends at (r, c1)
and Robot #2 ends at (r, c2)
    - Note that we will be moving both robots at the same time, ensuring that Robot #1 and Robot #2 will be at the same
    row number at all times
- Intially, dp[0][0][N-1] = grid[0][0]+grid[0][N-1]
    - We collect the cherries at the robot's starting points
- We can loop all possible dp states from top to bottom. For every (i, c1, c2):
    - Loop all 9 possible new dp states from the current dp state
        - (3 next moves from Robot #1) x (3 next moves from Robot #2) = 9 total
    - Update to each of the 9 next possible dp states
        - Note, if Robot #1 ends in the same cell as Robot #2, we can only add that cherry amount ONCE
- Finally, our answer is the maximum of all N*N possible ending states in the last row
    - Return the maximum of all dp[M-1][i][j], where 0<i, j<N

Time Complexity: O(M*N^2)
Memory Complexity: O(M*N^2)
*/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<vector<int>>>dp(M, vector<vector<int>>(N, vector<int>(N, -1e9)));
        vector<int>adj = {-1, 0, 1};
        dp[0][0][N-1] = grid[0][0]+grid[0][N-1];
        for(int i = 0;i<M-1;i++){
            for(int c1 = 0;c1<N;c1++){
                for(int c2 = 0;c2<N;c2++){
                    for(int dc1:adj){ //3 next moves for Robot #1
                        for(int dc2:adj){ //3 next moves for Robot #2
                            int nc1 = c1+dc1, nc2 = c2+dc2;
                            if(!(0<=nc1&&nc1<N&&0<=nc2&&nc2<N)){ //Check bounds
                                continue;
                            }
                            if(nc1==nc2){
                                //Robot #1 and Robot #2 end in the same cell
                                int t = dp[i][c1][c2]+grid[i+1][nc2];
                                dp[i+1][nc1][nc2] = max(dp[i+1][nc1][nc2], t);
                            }else{
                                //Robot #1 and Robot #2 DON'T end in the same cell
                                int t = dp[i][c1][c2]+grid[i+1][nc1]+grid[i+1][nc2];
                                dp[i+1][nc1][nc2] = max(dp[i+1][nc1][nc2], t);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                ans = max(ans, dp[M-1][i][j]);
            }
        }
        return ans;
    }
};