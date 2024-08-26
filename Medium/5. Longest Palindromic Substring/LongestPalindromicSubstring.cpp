/*
LeetCode Medium: 5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/description/

Brief Solution Explanation:
N = Length of string s
- This is a classic problem that can be solved with dynamic programming
  - For example: https://www.geeksforgeeks.org/longest-palindromic-substring
- Let dp[i][j] represent if the substring s[i:j] (including the ith and jth characters of s) are palindromic, True or False
  - Note that all dp[i][i] are palindromic since any 1 character word is a palindrome
  - We can determine the value of dp[i][j] by checking if BOTH of the following are true
    - dp[i+1][j-1] is true, if the substring s[i+1:j-1] is a palindrome
      - If dp[i+1][j-1] is false, dp[i][j] will always be false no matter what
    - s[i]==s[j]
      - If false, this means the characters at the ends of s[i:j] don't match
    - These two conditions MUST be true for s[i:j] to be a palindrome
- We can build this dp table by iterating all substrings in increasing length
  - In the code, I naively fill out all the dp table for all words of length 1 or 2 for generalization of length>=3 words
  - We must iterate in increasing length to ensure that dp[i+1][j-1] is already filled out before we reach dp[i][j]

Time Complexity: O(N^2)
Memory Complexity: O(N^2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        vector<vector<bool>>dp(N, vector<bool>(N, 0));
        //To Retrieve actual substring
        int st = 0, max_len = 0;
        for(int len = 1;len<=N;len++){
            for(int i = 0;i<N-len+1;i++){
                int j = i+len-1;
                if(len<=2){
                    dp[i][j] = s[i]==s[j];
                }else{
                    dp[i][j] = dp[i+1][j-1] & (s[i]==s[j]);
                }
                //Check for longest palindrome
                if(dp[i][j] && max_len<=len){
                    st = i;
                    max_len = len;
                }
            }
        }
        return s.substr(st, max_len);
    }
};