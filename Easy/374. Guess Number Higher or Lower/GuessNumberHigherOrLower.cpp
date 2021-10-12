/*
LeetCode Easy: 374. Guess Number Higher or Lower
https://leetcode.com/problems/guess-number-higher-or-lower/

Brief Solution Explanation:
- A simple binary search will suffice for this problem
- Remember to read the guess API function carefully as it returns 1 if your guess is too low
ans -1 if your guess is too high

Time Complexity: O(logN)
Memory Complexity: O(1)
*/
class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n, ans = 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2, q = guess(mid);
            if(q==0){
                ans = mid;
                break;
            }else if(q==1){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return ans;
    }
};