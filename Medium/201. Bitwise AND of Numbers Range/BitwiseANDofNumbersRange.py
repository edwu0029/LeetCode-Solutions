'''
LeetCode Medium: 201. Bitwise AND of Numbers Range
https://leetcode.com/problems/bitwise-and-of-numbers-range/

Check BitwiseANDofNumbersRange.cpp for brief solution explanation.
'''
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        ans = 0
        for i in range(31, -1, -1):
            l = 1 if (((1<<i)&left)>0) else 0
            r = 1 if (((1<<i)&right)>0) else 0
            if l==r:
                ans+=l*(1<<i)
            else:
                break
        return ans