/*
LeetCode Hard: 1987. Number of Unique Good Subsequences
https://leetcode.com/problems/number-of-unique-good-subsequences/

Check NumberOfUniqueGoodSubsequences.cpp for brief solution explanation.
*/
class Solution {
    public int numberOfUniqueGoodSubsequences(String binary) {
        int MOD = (int)1e9+7;
        int N = binary.length(), lst0 = -1, lst1 = -1;
        boolean has_zero = false;
        int[]dp = new int[N+1];
        for(int i = 1;i<=N;i++){
            dp[i] = (dp[i-1]*2)%MOD;
            if(binary.charAt(i-1)=='0'){
                if(lst0!=-1){
                    dp[i] = (dp[i]-dp[lst0-1]+MOD)%MOD;
                }
                lst0 = i;
                has_zero = true;
            }else{
                if(lst1!=-1){
                    dp[i] = (dp[i]-dp[lst1-1]+MOD)%MOD;
                }else{
                    dp[i] = 1;
                }
                lst1 = i;
            }
        }
        if(has_zero){
            return dp[N]+1;
        }else{
            return dp[N];
        }
    }
}