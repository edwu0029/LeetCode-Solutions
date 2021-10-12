'''
LeetCode Easy: 374. Guess Number Higher or Lower
https://leetcode.com/problems/guess-number-higher-or-lower/

Check GuessNumberHigherOrLower.cpp for brief solution explanation.
'''
class Solution:
    def guessNumber(self, n: int) -> int:
        lo, hi, ans = 1, n, 0
        while lo<=hi:
            mid = lo+(hi-lo)//2
            q = guess(mid)
            if q==0:
                ans = mid
                break
            elif q==1:
                lo = mid+1
            else:
                hi = mid-1
        return ans