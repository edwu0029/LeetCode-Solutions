'''
LeetCode Easy: 67. Add Binary
https://leetcode.com/problems/add-binary/

Check AddBinary.cpp for brief solution explanation.
'''
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a)<len(b):
            a, b = b, a
        a = a[::-1]
        b = b[::-1]
        carry = 0
        ans = ""
        for i in range(len(a)):
            cur = carry+ord(a[i])-ord('0')
            if i<len(b):
                cur+=ord(b[i])-ord('0')
            carry = cur//2
            ans+=chr((cur%2)+ord('0'))
        if carry>0:
            ans+=chr(carry+ord('0'))
        return ans[::-1]