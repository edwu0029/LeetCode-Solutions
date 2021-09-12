'''
LeetCode Medium: 1986. Minimum Number of Work Sessions to Finish the Tasks
https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/

Check MinimumNumberOfWorkSessionsToFinishTheTasks.cpp for brief solution explanation.
'''
class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        N = len(tasks)
        dp = [[0x3f3f3f3f for i in range(sessionTime+1)] for i in range(1<<N)]
        dp[0][sessionTime] = 1
        for mask in range(1<<N):
            for i in range(sessionTime+1):
                if dp[mask][i]==0x3f3f3f3f:
                    continue
                for j in range(N):
                    if (mask&(1<<j))>0:
                        continue
                    new_mask = mask|(1<<j)
                    if i>=tasks[j]:
                        dp[new_mask][i-tasks[j]] = min(dp[new_mask][i-tasks[j]], dp[mask][i])
                    else:
                        time_left = sessionTime-tasks[j]
                        dp[new_mask][time_left] = min(dp[new_mask][time_left], dp[mask][i]+1)
        ans = 0x3f3f3f3f
        for i in range(sessionTime+1):
            ans = min(ans, dp[(1<<N)-1][i])
        return ans