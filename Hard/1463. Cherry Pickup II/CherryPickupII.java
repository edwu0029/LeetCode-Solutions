/*
LeetCode Hard: 1463. Cherry Pickup II
https://leetcode.com/problems/cherry-pickup-ii/

Check CherryPickupII.cpp for brief solution explanation.
*/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<vector<int>>>dp(M, vector<vector<int>>(N, vector<int>(N)));
        //Fill array with -inf
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                for(int k = 0;k<N;k++){
                    dp[i][j][k] = -1e9;
                }
            }
        }
        vector<int>adj = {-1, 0, 1};
        dp[0][0][N-1] = grid[0][0]+grid[0][N-1];
        for(int i = 0;i<M-1;i++){
            for(int c1 = 0;c1<N;c1++){
                for(int c2 = 0;c2<N;c2++){
                    for(int dc1:adj){
                        for(int dc2:adj){
                            int nc1 = c1+dc1, nc2 = c2+dc2;
                            if(!(0<=nc1&&nc1<N&&0<=nc2&&nc2<N)){
                                continue;
                            }
                            if(nc1==nc2){
                                int t = dp[i][c1][c2]+grid[i+1][nc2];
                                dp[i+1][nc1][nc2] = max(dp[i+1][nc1][nc2], t);
                            }else{
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