'''
LeetCode Medium: 1010. Pairs of Songs With Total Durations Divisible by 60
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

Check PairsOfSongsWithTotalDurationsDivisibleBy60.cpp for brief solution explanation.
'''
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        N = len(time)
        cnt = [[0 for i in range(N)] for i in range(60)]
        for i in range(N):
            rem = time[i]%60
            cnt[rem][i]+=1
            if i>0:
                for j in range(60):
                    cnt[j][i]+=cnt[j][i-1]
        ans = 0
        for i in range(1, N):
            needed = (60-(time[i]%60))%60
            ans+=cnt[needed][i-1]
        return ans