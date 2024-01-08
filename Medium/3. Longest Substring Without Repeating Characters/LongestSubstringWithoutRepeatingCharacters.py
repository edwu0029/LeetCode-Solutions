'''
LeetCode Medium: 3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Check LongestSubstringWithoutRepeatingCharacters.cpp for brief solution explanation.
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        N = len(s)
        if(N==0):
            return 0
        l, r, ans, = 0, 0, 0
        freq = defaultdict(int)
        while l<N:
            while r<N and freq[s[r]]==0:
                freq[s[r]]+=1
                r+=1
            ans = max(ans, r-l)
            freq[s[l]]-=1
            l+=1
        ans = max(ans, r-l)
        return ans
