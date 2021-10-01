/*
LeetCode Medium: 1143. Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/

Check LongestCommonSubsequence.cpp for brief solution explanation.
*/
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        if(text1.length()<text2.length()){
            String t = text2;
            text2 = text1;
            text1 = t;
        }
        int N = text1.length(), M = text2.length();
        int[][]dp = new int[2][M+1];
        int pre = 0, cur = 1;
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=M;j++){
                if(text1.charAt(i-1)==text2.charAt(j-1)){
                    dp[cur][j] = dp[pre][j-1]+1;
                }else{
                    dp[cur][j] = Math.max(dp[pre][j], dp[cur][j-1]);
                }
            }
            pre^=1;
            cur^=1;
        }
        return dp[pre][M];
    }
}