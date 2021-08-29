'''
LeetCode Easy: 9. Palindrome Number
https://leetcode.com/problems/palindrome-number/

Check PalindromeNumber.cpp for brief solution explanation.
'''
class Solution:
    def isPalindrome(self, x: int) -> bool:
        num = str(x)
        N = len(num)
        for i in range(N//2):
            if num[i]!=num[N-i-1]:
                return False
        return True