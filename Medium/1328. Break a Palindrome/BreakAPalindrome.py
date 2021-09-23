'''
LeetCode Medium: 1328. Break a Palindrome
https://leetcode.com/problems/break-a-palindrome/

Check BreakAPalindrome.cpp for brief solution explanation.
'''
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        N = len(palindrome)
        if N==1:
            return ""
        ans = ""
        done = False
        for i in range(N//2):
            if palindrome[i]!='a':
                ans = palindrome[0:i]+"a"+palindrome[i+1:]
                done = True
                break
        if not done:
            ans = palindrome[0:N-1]+"b"
        return ans