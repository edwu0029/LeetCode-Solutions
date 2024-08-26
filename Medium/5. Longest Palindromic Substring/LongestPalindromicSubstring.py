'''
LeetCode Medium: 5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/description/

Check LongestPalindromicSubstring.cpp for brief solution explanation.
'''
class Solution:
    def longestPalindrome(self, s: str) -> str:
        N = len(s)
        dp = [[False for i in range(N)] for j in range(N)]
        st, ed = 0, 0
        for length in range(1, N+1):
            for i in range(N-length+1):
                j = i+length-1
                if length<=2:
                    dp[i][j] = s[i]==s[j]
                else:
                    dp[i][j] = dp[i+1][j-1] & (s[i]==s[j])
                # Keep track of best
                if dp[i][j] and ed-st+1<=length:
                    st, ed = i, j
        return s[st:ed+1]