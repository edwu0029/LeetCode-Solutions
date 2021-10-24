'''
LeetCode Medium: 451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/

Check SortCharactersByFrequency.cpp for brief solution explanation.
'''
class Solution:
    def frequencySort(self, s: str) -> str:
        N = len(s)
        m = {}
        for i in s:
            if i in m:
                m[i]+=1
            else:
                m[i] = 1
        buckets = [[] for i in range(N+1)]
        for i in m.keys():
            freq = m[i]
            buckets[freq].append(i)
        ans = ""
        for i in range(N, 0, -1):
            if len(buckets[i])<=0:
                continue
            for j in buckets[i]:
                for k in range(i):
                    ans+=j
        return ans