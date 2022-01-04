'''
LeetCode Easy: 1189. Maximum Number of Balloons
https://leetcode.com/problems/maximum-number-of-balloons/

Check ComplementOfBase10Integer.cpp for brief solution explanation.
'''
class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n==0:
            return 1
        complement = 0
        for i in range(int(log2(n))):
            if not (1<<i)&n:
                complement+=(1<<i)
        return complement