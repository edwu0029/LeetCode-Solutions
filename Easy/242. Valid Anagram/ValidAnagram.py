'''
LeetCode Easy: 242. Valid Anagram
https://leetcode.com/problems/valid-anagram/description/

Check ValidAnagram.cpp for brief solution explanation.
'''
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        Ns, Nt = len(s), len(t)
        if(Ns!=Nt):
            return False
        freqs = [0 for i in range(26)]
        freqt = [0 for i in range(26)]
        for i in range(Ns):
            freqs[ord(s[i])-ord('a')]+=1
            freqt[ord(t[i])-ord('a')]+=1
        for i in range(26):
            if(freqs[i]!=freqt[i]):
                return False
        return True