'''
LeetCode Easy: 1189. Maximum Number of Balloons
https://leetcode.com/problems/maximum-number-of-balloons/

Check MaximumNumberOfBalloons.cpp for brief solution explanation.
'''
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        N = len(text)
        freq = [0 for i in range(26)]
        for i in range(N):
            freq[ord(text[i])-ord('a')]+=1
        ans = freq[ord('b')-ord('a')]
        ans = min(ans, freq[0])
        ans = min(ans, freq[ord('l')-ord('a')]//2)
        ans = min(ans, freq[ord('o')-ord('a')]//2)
        ans = min(ans, freq[ord('n')-ord('a')])
        return ans