'''
LeetCode Medium: 151. Reverse Words in a String
https://leetcode.com/problems/reverse-words-in-a-string/

Check ReverseWordsInAString.cpp for brief solution explanation.
'''
class Solution:
    def reverseWords(self, s: str) -> str:
        N = len(s)
        l, r = N-1, N-1
        ans = ""
        while True:
            while r>=0 and s[r]==' ':
                l-=1
                r-=1
            if l<0 or r<0:
                break
            while l>=1 and s[l-1]!=' ':
                l-=1
            ans+=s[l:r+1]+" "
            r = l = l-1
        return ans.strip()