'''
LeetCode Medium: 1094. Car Pooling
https://leetcode.com/problems/car-pooling/

Check CarPooling.cpp for brief solution explanation.
'''
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        D = 0
        for n, f, t in trips:
            D = max(D, t+1)
        sums = [0 for i in range(D+1)]
        for n, f, t in trips:
            sums[f]+=n
            sums[t]-=n
        for i in range(D+1):
            if i>0:
                sums[i]+=sums[i-1]
            if sums[i]>capacity:
                return False
        return True