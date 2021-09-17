'''
LeetCode Easy: 14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/

Check LongestCommonPrefix.cpp for brief solution explanation.
'''
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        min_len = len(strs[0])
        for i in range(len(strs)):
            min_len = min(min_len, len(strs[i]))
        for i in range(min_len):
            all_same = True
            c = strs[0][i]
            for j in range(len(strs)):
                if c!=strs[j][i]:
                    all_same = False
                    break
            if not all_same:
                break
            prefix+=c
        return prefix