/*
LeetCode Medium: 1143. Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/

Brief Solution Explanation:
N = Length of text1
M = Length of text2
- This is a classic problem
https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
- We can use a dp approach to solve this problem
- For simplicity sake, let's assume text1 and text2 are 1-indexed strings
- Let dp[i][j] = Longest Common Subsequence for substrings text1[1:i] and text2[1:j]
- If text1[i]==text2[j], we can add this common character to our best without the ith text1 character
and jth text2 character, namely dp[i-1][j-1]
    - Thus dp[i][j] = dp[i-1][j-1]+1
- If they aren't equal, we need to find our best answer between dp[i-1][j] and dp[i][j-1]
    - Thus dp[i][j] = max(dp[i-1][j], dp[i][j-1])
- Since we only need to keep the current and previous rows, we only need to keep track of 2 rows at a time
    - Reduces memory complexity from O(NM) to O(min(N, M))

Time Complexity: O(NM)
Memory Complexity: O(min(N, M))
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()<text2.size()){
            swap(text1, text2);
        }
        int N = text1.size(), M = text2.size();
        int pre = 0, cur = 1;
        vector<vector<int>>dp(2, vector<int>(M+1, 0));
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=M;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[cur][j] = dp[pre][j-1]+1;
                }else{
                    dp[cur][j] = max(dp[pre][j], dp[cur][j-1]);
                }
            }
            swap(pre, cur);
        }
        return dp[pre][M];
    }
};