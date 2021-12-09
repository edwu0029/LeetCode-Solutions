'''
LeetCode Hard: 72. Edit Distance
https://leetcode.com/problems/edit-distance/

Check EditDistance.cpp for brief solution explanation.
'''

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if len(word1)<len(word2):
            word1, word2 = word2, word1
        N, M = len(word1), len(word2)
        dp = [[0 for i in range(M+1)] for i in range(2)]
        pre, cur = 0, 1
        for i in range(M+1):
            dp[pre][i] = i
        for i in range(1, N+1):
            dp[cur][0] = i
            for j in range(1, M+1):
                if word1[i-1]==word2[j-1]:
                    dp[cur][j] = dp[pre][j-1]
                    continue
                dp[cur][j] = 0x3f3f3f3f
                dp[cur][j] = min(dp[cur][j], dp[pre][j-1]+1);
                dp[cur][j] = min(dp[cur][j], dp[pre][j]+1);
                dp[cur][j] = min(dp[cur][j], dp[cur][j-1]+1);
            pre, cur = cur, pre
        pre, cur = cur, pre
        return dp[cur][M]