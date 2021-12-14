/*
LeetCode Hard: 72. Edit Distance
https://leetcode.com/problems/edit-distance/

Brief Solution Explanation:
N = Length of word1
M = Length of word2
- This is a classic dp problem to find the minimum edit distance/levenshtein distance between two words
https://www.geeksforgeeks.org/edit-distance-dp-5/
- From now on, let us assume word1 and word2 are 1-indexed strings
- Let dp[i][j] = Minimum number of moves to make the prefixes word1[1:i]=word2[1:j]
- Intially our base case is:
    - dp[0][0] = 0, takes 0 moves to make word1[0:0] to word2[0:0]
    - dp[i][0] for all 0<=i<=N, takes i moves to the first i letters of word1 to word2[0:0]
    - dp[0][i] for all 0<=i<=M, takes i moves to the first i letters of word2 to word1[0:0]
- We can simply loop through the rest of the dp table and figure out the transition for each dp[i][j]
    - If word1[i]==word2[j]:
        - we simply need to make the previous prefixes word1[1:i-1]==word2[1:j-1] as we don't need to do
    anything to make word1[i] and word2[j] equal
        - dp[i][j] = dp[i-1][j-1]
    - Otherwise, we will need to actually make a move to make the prefixes equal
    - Modify ith letter of word1 to match jth letter of word2:
        - dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1)
    - Add the jth letter of word2 to the end of word1[1:i-1]
        - dp[i][j] = min(dp[i][j], dp[i-1][j]+1)
    - Add the ith letter of word1 to the end of word2[1:j-1]
        - dp[i][j] = min(dp[i][j], dp[i][j-1]+1)
- Our final result is dp[N][M]

- Notice that our dp transition only relies on the previous row, so we don't need to keep track of the
rest of the rows of the dp table
- Thus, our dp table only needs to 2 rows instead of N rows
- To minimize the number of columns, we can simply swap word1 and word2 to always make word2 the shorter of
the two words

Time Complexity: O(N*M)
Memory Complexity: O(min(N, M))
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()<word2.size()){
            swap(word1, word2);
        }
        int N = word1.size(), M = word2.size();
        vector<vector<int>>dp(2, vector<int>(M+1));
        int pre = 0, cur = 1;
        for(int i = 0;i<=M;i++){
            dp[pre][i] = i;
        }
        for(int i = 1;i<=N;i++){
            dp[cur][0] = i;
            for(int j = 1;j<=M;j++){
                if(word1[i-1]==word2[j-1]){
                    //Just need to make word1[1:i-1] = word2[1:j-1]
                    dp[cur][j] = dp[pre][j-1];
                    continue;
                }
                dp[cur][j] = 0x3f3f3f3f;
                //Modify ith letter of word1 to match jth letter of word2
                dp[cur][j] = min(dp[cur][j], dp[pre][j-1]+1);
                //Add jth letter of word2 to the end of word1[1:i-1]
                dp[cur][j] = min(dp[cur][j], dp[pre][j]+1);
                //Ad ith letter of word1 to the end of word2[1:j-1]
                dp[cur][j] = min(dp[cur][j], dp[cur][j-1]+1);
            }
            swap(cur, pre);
        }
        swap(cur, pre);
        return dp[cur][M];
    }
};