'''
LeetCode Medium: 1318. Minimum Flips to Make a OR b Equal to c
https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

Check MinimumFlipsToMakeaORbEqualToc.cpp for brief solution explanation.
'''
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        count = 0
        i = 0
        while((1<<i)<=max(a, max(b, c))):
            a_i = (1<<i)&a
            b_i = (1<<i)&b
            c_i = (1<<i)&c
            if c_i==0:
                if a_i>0:
                    count+=1
                if b_i>0:
                    count+=1
            else:
                if a_i+b_i==0:
                    count+=1
            i+=1
        return count