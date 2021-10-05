'''
LeetCode Easy: 70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/

Check ClimbingStairs.cpp for brief solution explanation.
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        a, b, c = 1, 1, 0
        for i in range(2, n+1):
            c = a+b
            a, b, c = b, c, 0
        return b