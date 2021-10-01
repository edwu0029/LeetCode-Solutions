'''
LeetCode Medium: 1143. Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/

Check LongestCommonSubsequence.cpp for brief solution explanation.
'''
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if len(text1)<len(text2):
            text1, text2 = text2, text1
        N, M = len(text1), len(text2)
        dp = [[0 for i in range(M+1)] for i in range(2)]
        pre, cur = 0, 1
        for i in range(1, N+1):
            for j in range(1, M+1):
                if text1[i-1]==text2[j-1]:
                    dp[cur][j] = dp[pre][j-1]+1
                else:
                    dp[cur][j] = max(dp[pre][j], dp[cur][j-1])
            pre, cur = cur, pre
        return dp[pre][M]