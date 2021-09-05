'''
LeetCode Hard: 1987. Number of Unique Good Subsequences
https://leetcode.com/problems/number-of-unique-good-subsequences/

Check NumberOfUniqueGoodSubsequences.cpp for brief solution explanation.
'''
class Solution:
    def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
        MOD = int(1e9+7)
        N, lst0, lst1 = len(binary), -1, -1
        has_zero = False
        dp = [0 for i in range(N+1)]
        for i in range(1, N+1):
            dp[i] = (dp[i-1]*2)%MOD
            if binary[i-1]=='0':
                if lst0!=-1:
                    dp[i] = (dp[i]-dp[lst0-1]+MOD)%MOD
                lst0 = i
                has_zero = True
            else:
                if lst1!=-1:
                    dp[i] = (dp[i]-dp[lst1-1]+MOD)%MOD
                else:
                    dp[i] = 1
                lst1 = i
        if has_zero:
            return dp[N]+1
        else:
            return dp[N]