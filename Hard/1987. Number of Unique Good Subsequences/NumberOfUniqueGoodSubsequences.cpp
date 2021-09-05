/*
LeetCode Hard: 1987. Number of Unique Good Subsequences
https://leetcode.com/problems/number-of-unique-good-subsequences/

Brief Solution Explanation:
N = Length of binary string
- We can use a dynamic programming to solve this program. For now we will not consider the subsequence "0".

- For simplicity sake, I will assume that the binary string is 1-indexed (Index 1, 2, 3..., N)

- dp state: dp[i] = Number of unique subsequences in substring [1:i] with NO leading zeros
- Base case: dp[fst1] = 1, where fst1 is the index of the left-most one
- Let us consider some index i:
    - We know that we can add this current digit to all previous substrings, dp[i-1], to make 2*dp[i-1] new subsequences
    - However we must consider that of these 2*dp[i-1] new subsequences, some may be overcounted. We need to substract these
    - To do this, we have to look a the previous index of this current digit(If it exists), let this index be j
    - It can be shown that dp[j-1] is the number of over-counted subsequnces since these were already counted in dp[j]. Remember binary[j]==binary[i]
    - Thus we need to do dp[i]-=dp[j-1]
- FInally, we need to consider the subsequence "0". We can just add 1 to dp[N] if a zero appears in the subsequence
- All operations are done with modular arithmetic

Time Complexity: O(N)
- Memory complexity can be simplified to O(1), but for clarity sake, the code below is in O(N) memory
Memory Complexity: O(N)
*/
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int MOD = (int)1e9+7;
        int N = binary.size(), lst0 = -1, lst1 = -1;
        vector<int>dp(N+1);
        bool has_zero = false;
        for(int i = 1;i<=N;i++){
            dp[i] = (dp[i-1]*2)%MOD;
            if(binary[i-1]=='0'){
                if(lst0!=-1){
                    dp[i] = (dp[i]-dp[lst0-1]+MOD)%MOD;
                }
                lst0 = i;
                has_zero = true;
            }else{
                if(lst1!=-1){
                    dp[i] = (dp[i]-dp[lst1-1]+MOD)%MOD;
                }else{
                    //When meet first one, make dp[i] = 1
                    dp[i] = 1;
                }
                lst1 = i;
            }
        }
        return dp[N]+has_zero;
    }
};