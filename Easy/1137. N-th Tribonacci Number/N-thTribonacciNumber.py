'''
LeetCode Easy: 1137. N-th Tribonacci Number
https://leetcode.com/problems/n-th-tribonacci-number/

Check N-thTribonacciNumber.cpp for brief solution explanation.
'''
class Solution:
    def tribonacci(self, n: int) -> int:
        tribonacci = [0 for i in range(max(3, n+1))]
        tribonacci[0] = 0
        tribonacci[1] = 1
        tribonacci[2] = 1
        for i in range(3, n+1):
            tribonacci[i] = tribonacci[i-1]+tribonacci[i-2]+tribonacci[i-3]
        return tribonacci[n]