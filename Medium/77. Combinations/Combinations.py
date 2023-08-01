'''
LeetCode Medium: 77. Combinations
https://leetcode.com/problems/combinations/

Check Combinations.cpp for brief solution explanation.
'''
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        cur = []
        def dp(n, k, idx, cur, ans):
            if k==0:
                ans.append(cur[:])
                return
            if idx>n:
                return
            dp(n, k, idx+1, cur, ans)
            cur.append(idx)
            dp(n, k - 1, idx + 1, cur, ans)
            cur.pop()
        dp(n, k, 1, cur, ans)
        return ans