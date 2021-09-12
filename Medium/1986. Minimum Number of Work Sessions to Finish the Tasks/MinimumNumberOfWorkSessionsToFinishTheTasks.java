/*
LeetCode Medium: 1986. Minimum Number of Work Sessions to Finish the Tasks
https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/

Check MinimumNumberOfWorkSessionsToFinishTheTasks.cpp for brief solution explanation.
*/
class Solution {
    public int minSessions(int[] tasks, int sessionTime) {
        int N = tasks.length;
        int[][]dp = new int[(1<<N)][sessionTime+1];
        for(int i = 0;i<(1<<N);i++){
            for(int j = 0;j<=sessionTime;j++){
                dp[i][j] = 0x3f3f3f3f;
            }
        }
        dp[0][sessionTime] = 1;
        for(int mask = 0;mask<(1<<N);mask++){
            for(int i = 0;i<=sessionTime;i++){
                if(dp[mask][i]==0x3f3f3f3f){
                    continue;
                }
                for(int j = 0;j<N;j++){
                    if((mask&(1<<j))>0) continue;
                    int new_mask = mask|(1<<j);
                    if(i>=tasks[j]){ //Use current session to do task j
                        dp[new_mask][i-tasks[j]] = Math.min(dp[new_mask][i-tasks[j]], dp[mask][i]);
                    }else{ //Need another session to do task j
                        int time_left = sessionTime-tasks[j];
                        dp[new_mask][time_left] = Math.min(dp[new_mask][time_left], dp[mask][i]+1);
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0;i<=sessionTime;i++){
            ans = Math.min(ans, dp[(1<<N)-1][i]);
        }
        return ans;
    }
}