'''
LeetCode Medium: 49. Group Anagrams
https://leetcode.com/problems/group-anagrams/description/

Check GroupAnagrams.cpp for brief solution explanation.
'''
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        N = len(strs)
        m = {}
        for i in range(N):
            cur = tuple(sorted(tuple(strs[i])))
            if(cur not in m):
                m[cur] = []
            m[cur].append(strs[i])
        ans = m.values()
        return ans