'''
LeetCode Easy: 997. Find the Town Judge
https://leetcode.com/problems/find-the-town-judge/

Check FindTheTownJudge.cpp for brief solution explanation.
'''
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        indegree = [0 for i in range(n+1)]
        outdegree = [0 for i in range(n+1)]
        T = len(trust)
        for i in range(T):
            a, b = trust[i][0], trust[i][1]
            outdegree[a]+=1
            indegree[b]+=1
        for i in range(1, n+1):
            if outdegree[i]==0 and indegree[i]==n-1:
                return i
        return -1
