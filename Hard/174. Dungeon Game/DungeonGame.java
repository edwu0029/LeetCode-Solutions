'''
LeetCode Hard: 174. Dungeon Game
https://leetcode.com/problems/dungeon-game/

Check DungeonGame.cpp for brief solution explanation.
'''
class Solution {
public:
    bool bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size(), N = dungeon[0].size();
        vector<vector<int>>dp(M, vector<int>(N, 0));
        if(dungeon[M-1][N-1]>=0){
            dp[M-1][N-1] = 1;
        }else{
            dp[M-1][N-1] = -dungeon[M-1][N-1]+1;
        }
        for(int i = M-1;i>=0;i--){
            for(int j = N-1;j>=0;j--){
                if(i==M-1&&j==N-1){
                    continue;
                }
                int t = 0x3f3f3f3f;
                if(bounds(i+1, j, M, N)){
                    t = min(t, dp[i+1][j]);
                }
                if(bounds(i, j+1, M, N)){
                    t = min(t, dp[i][j+1]);
                }
                dp[i][j] = max(t-dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};