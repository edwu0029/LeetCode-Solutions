'''
LeetCode Easy: 1979. Find Greatest Common Divisor of Array
https://leetcode.com/problems/find-greatest-common-divisor-of-array/

Check FindGreatestCommonDivisorOfArray.cpp for brief solution explanation.
'''
class Solution:
    def findGCD(self, nums: List[int]) -> int:
        def fast_gcd(a, b) -> int:
            if b==0:
                return a
            else:
                return fast_gcd(b, a%b)
        N = len(nums)
        max_num, min_num = -1, 1005
        for i in range(N):
            max_num = max(max_num, nums[i])
            min_num = min(min_num, nums[i])
        return fast_gcd(max_num, min_num)