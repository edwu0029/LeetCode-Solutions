/*
LeetCode Medium: 5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/description/

Check LongestPalindromicSubstring.cpp for brief solution explanation.
*/
class Solution {
    public String longestPalindrome(String s) {
        int N = s.length();
        boolean[][]dp = new boolean[N][N];
        int st = 0, ed = 0;
        for(int len = 1;len<=N;len++){
            for(int i = 0;i<N-len+1;i++){
                int j = i+len-1;
                if(len<=2){
                    dp[i][j] = (s.charAt(i)==s.charAt(j));
                }else{
                    dp[i][j] = dp[i+1][j-1] & (s.charAt(i)==s.charAt(j));
                }
                //Check for longest palindrome
                if(dp[i][j] && ed-st+1<=len){
                    st = i;
                    ed = j;
                }
            }
        }
        return s.substring(st, ed+1);
    }
}