'''
LeetCode Hard: 72. Edit Distance
https://leetcode.com/problems/edit-distance/

Check EditDistance.cpp for brief solution explanation.
'''

class Solution {
    public int minDistance(String word1, String word2) {
        if(word1.length()<word2.length()){
            String tmp = word1;
            word1 = word2;
            word2 = tmp;
        }
        int N = word1.length(), M = word2.length();
        int[][]dp = new int[2][M+1];
        int pre = 0, cur = 1;
        for(int i = 0;i<=M;i++){
            dp[pre][i] = i;
        }
        for(int i = 1;i<=N;i++){
            dp[cur][0] = i;
            for(int j = 1;j<=M;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    dp[cur][j] = dp[pre][j-1];
                    continue;
                }
                dp[cur][j] = 0x3f3f3f3f;
                dp[cur][j] = Math.min(dp[cur][j], dp[pre][j-1]+1);
                dp[cur][j] = Math.min(dp[cur][j], dp[pre][j]+1);
                dp[cur][j] = Math.min(dp[cur][j], dp[cur][j-1]+1);
            }
            pre^=1;
            cur^=1;
        }
        pre^=1;
        cur^=1;
        return dp[cur][M];
    }
}