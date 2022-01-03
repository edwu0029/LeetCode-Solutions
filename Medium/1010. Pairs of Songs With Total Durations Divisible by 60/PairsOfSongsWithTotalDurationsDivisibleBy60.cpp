/*
LeetCode Medium: 1010. Pairs of Songs With Total Durations Divisible by 60
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

Brief Solution Explanation:
N = Length of time array
- Since we are looking for divisibility by 60, we only need to look at the duration of each song mod 60
- Using these values, we can build a prefix sum array of these modded values
    - Let cnt[i][j] = Numeber of songs with remainder i from the first j songs
- Using the prefix sum array, we can compute the answer for each song, time[i], where that song is included in the pair
    - To prevent overcounting, we will always assume that time[i] is the rightmost song in the pair
    - We can compute the remainder needed by the other song to make the sum%60==0
        - needed = (60-(time[i]%60))%60
    - To find the number of songs to the left of time[i] with the needed remainder, we use the prefix sum array
    value of cnt[needed][i-1]

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int N = time.size();
        vector<vector<int>>cnt(60, vector<int>(N));
        //Compute prefix sum array
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
};