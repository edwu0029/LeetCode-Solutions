/*
LeetCode Medium: 1986. Minimum Number of Work Sessions to Finish the Tasks
https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/

Brief Solution Explanation:
N = Length of tasks
- Since N is relatively small(Only going up to 14), we can use bitmasks and dynamic programming to solve this
- dp state: dp[i][j] = minimum number of sessions to finish the sessions repsented by the bitmask i, with j minutes left
in the current session
    - For the bitmask i, let the right most digit represent the first task, second-right most digit represent the second task, ... and so on
    - If the digit is 0, that task has NOT been finished
    - If the digit is 1, that task HAS been finished
- Intial state: dp[0][sessionTime] = 1
- Loop through all dp states, let us consider the state dp[mask][i]
    - mask = bitmask of current state of tasks
    - i = Time left in current session
    - To do our transition, we first must find all tasks that have NOT been finished. This can easily be found using the bitmask.
    Let j be a task that has not been finished with the current dp state
        - If i>=tasks[j], we can still use our current session
        - If i<tasks[j], we need to add another session to do task j
- The final answer is the smallest of all dp[(1<<N)-1][i], 0<=i<=sessionTime

Time Complexity: O(2^N*sessionTime*N)
Memory Complexity: O(2^N*sessionTime)
*/
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int N = tasks.size();
        vector<vector<int>>dp((1<<N), vector<int>(sessionTime+1, 0x3f3f3f3f));
        dp[0][sessionTime] = 1;
        for(int mask = 0;mask<(1<<N);mask++){
            for(int i = 0;i<=sessionTime;i++){
                if(dp[mask][i]==0x3f3f3f3f){
                    continue;
                }
                for(int j = 0;j<N;j++){
                    if(mask&(1<<j)) continue;
                    int new_mask = mask|(1<<j);
                    if(i>=tasks[j]){ //Use current session to do task j
                        dp[new_mask][i-tasks[j]] = min(dp[new_mask][i-tasks[j]], dp[mask][i]);
                    }else{ //Need another session to do task j
                        int time_left = sessionTime-tasks[j];
                        dp[new_mask][time_left] = min(dp[new_mask][time_left], dp[mask][i]+1);
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0;i<=sessionTime;i++){
            ans = min(ans, dp[(1<<N)-1][i]);
        }
        return ans;
    }
};