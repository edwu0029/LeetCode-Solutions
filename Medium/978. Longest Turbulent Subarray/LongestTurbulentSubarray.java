/*
LeetCode Medium: 978. Longest Turbulent Subarray
https://leetcode.com/problems/longest-turbulent-subarray/

Check LongestTurbulentSubarray.cpp for brief solution explanation.
*/
class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int N = arr.length, ans = 1, inc = 1, dec = 1;
        for(int i = 1;i<N;i++){
            if(arr[i-1]==arr[i]){
                inc = dec = 1;
            }else if(arr[i-1]>arr[i]){
                dec = inc+1;
                inc = 1;
            }else{
                inc = dec+1;
                dec = 1;
            }
            ans = Math.max(ans, Math.max(inc, dec));
        }
        return ans;
    }
}