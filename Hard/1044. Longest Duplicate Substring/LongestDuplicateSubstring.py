'''
LeetCode Hard: 1044. Longest Duplicate Substring
https://leetcode.com/problems/longest-duplicate-substring/

Check LongestDuplicateSubstring.cpp for brief solution explanation.
'''
class Solution:
    def check_same(self, a, b) -> bool:
        return a[0]==b[0] and a[1]==b[1]

    def longestDupSubstring(self, s: str) -> str:
        N = len(s)
        #Build Suffix array
        rank = [[0 for i in range(N)] for i in range(int(math.log2(N))+2)]
        for i in range(N):
            rank[0][i] = ord(s[i])-ord('a')
        t, stp, cnt = 0, 1, 1
        while (1<<(stp-1))<N:
            t = stp
            p = []
            for i in range(N):
                tmp = [0 for i in range(3)]
                tmp[0] = rank[stp-1][i]
                tmp[1] = rank[stp-1][i+cnt] if i+cnt<N else -1
                tmp[2] = i
                p.append(tmp)
            p.sort()
            for i in range(N):
                if i>0 and self.check_same(p[i], p[i-1]):
                    rank[stp][p[i][2]] = rank[stp][p[i-1][2]]
                else:
                    rank[stp][p[i][2]] = i
            stp+=1
            cnt<<=1
        sa = [0 for i in range(N)]
        for i in range(N):
            sa[rank[t][i]] = i
        #Kasai Algorithm
        lcp = [0 for i in range(N)]
        k = 0
        for i in range(N):
            if rank[t][i]==N-1:
                k = 0
                continue
            j = sa[rank[t][i]+1]
            while i+k<N and j+k<N and s[i+k]==s[j+k]:
                k+=1
            lcp[rank[t][i]] = k
            k = max(0, k-1)
        #Find answer substring
        sz, l = 0, 0
        for i in range(N):
            if sz<lcp[i]:
                l = sa[i]
                sz = lcp[i]
        if len==0:
            return ""
        else:
            return s[l:l+sz]
        return ""