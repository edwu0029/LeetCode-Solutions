/*
LeetCode Easy: 374. Guess Number Higher or Lower
https://leetcode.com/problems/guess-number-higher-or-lower/

Check GuessNumberHigherOrLower.cpp for brief solution explanation.
*/
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int lo = 1, hi = n, ans = 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2, q = guess(mid);
            if(q==0){
                ans = mid;
                break;
            }else if(q>0){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return ans;
    }
}