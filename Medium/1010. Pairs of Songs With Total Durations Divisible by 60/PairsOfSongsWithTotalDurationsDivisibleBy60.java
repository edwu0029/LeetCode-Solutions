/*
LeetCode Medium: 1010. Pairs of Songs With Total Durations Divisible by 60
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

Check PairsOfSongsWithTotalDurationsDivisibleBy60.cpp for brief solution explanation.
*/
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int N = time.length;
        int[][]cnt = new int[60][N];
        for(int i = 0;i<N;i++){
            int rem = time[i]%60;
            cnt[rem][i]++;
            if(i>0){
                for(int j = 0;j<60;j++){
                    cnt[j][i]+=cnt[j][i-1];
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<N;i++){
            int needed = (60-(time[i]%60))%60;
            ans+=cnt[needed][i-1];
        }
        return ans;
    }
}