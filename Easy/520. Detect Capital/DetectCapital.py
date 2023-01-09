'''
LeetCode Easy: 520. Detect Capital
https://leetcode.com/problems/detect-capital/

Check DetectCapital.cpp for brief solution explanation.
'''
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        N = len(word)
        capitals = 0
        for i in word:
            if i.isupper():
                capitals+=1
        if capitals==0 or capitals==N or (capitals==1 and word[0].isupper()):
            return True
        else:
            return False