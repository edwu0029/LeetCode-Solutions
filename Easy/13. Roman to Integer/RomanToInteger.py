'''
LeetCode Easy: 13. Roman to Integer
https://leetcode.com/problems/roman-to-integer/

Check RomanToInteger.cpp for brief solution explanation.
'''
class Solution:
    def romanToInt(self, s: str) -> int:
        legend = {'I':1, 'V': 5, 'X':10, 'L': 50, 'C': 100, 'D':500, 'M':1000}
        pre_value = 10000
        ans = 0
        for i in s:
            cur_value = legend[i]
            if pre_value<legend[i]:
                ans-=2*pre_value
            ans+=cur_value
            pre_value = cur_value
        return ans