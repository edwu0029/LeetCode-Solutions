/*
LeetCode Hard: 174. Dungeon Game
https://leetcode.com/problems/dungeon-game/

Brief Solution Explanation:
M = Number of rows
N = Number of columns
- We can use a dp approach, starting from the end and working toward the start to solve this problem
- Optimally, we would want to end up with just 1hp when we reach the princess(bottom-right corner)
- Let dp[i][j] = Minimum starting hp to reach the princess if we START from (i, j)
- Intially, our base case is:
    - If dungeon[M-1][N-1]>=0, dp[M-1][N-1] = 1
    - If dungeon[M-1][N-1]<0, dp[M-1][N-1] = -dungeon[M-1][N-1]+1
- We can then find some dp[i][j] based on its two neighbours dp[i+1][j] and dp[i][j+1]
    - *Remember we are working backwards so we use dp[i+1][j] and dp[i][j+1] rather than dp[i-1][j] and dp[i][j-1]*
    - We first need to find the better answer between the two(Smaller intial hp) which is min(dp[i-1][j], dp[i][j-1]), lets call this t
    - Now, we must factor in the value of the current room, dungeon[i][j]
    - To survive, dp[i][j] = t-dungeon[i][j]
       - If dungeon[i][j] is negative, we obviosuly need more intial health
       - If dungeon[i][j] is positive, we can have less intial health
       - However if dungeon[i][j] is a very large positive number, such that t-dungeon[i][j]<=0, than we know that we can just start with
       1hp in that room
    - Thus dp[i][j] = max(t-dungeon[i][j], 1)
- Our final answer is dp[0][0]

Time Complexity: O(M*N)
- Since we are only looking at two rows at a time, memory complexity can be reduced
from O(M*N) to O(min(M, N)). However for clarity sake, the code below is O(M*N) memory
Memory Complexity: O(M*N)
*/
class Solution {
public:
    bool bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size(), N = dungeon[0].size();
        vector<vector<int>>dp(M, vector<int>(N));
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