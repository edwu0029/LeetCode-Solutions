'''
LeetCode Medium: 1985. Find the Kth Largest Integer in the Array
https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

Check FindTheKthLargestIntegerInTheArray.cpp for brief solution explanation.
'''
from functools import cmp_to_key
class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        def cmp(a, b):
            if len(a)==len(b):
                if a<b:
                    return -1
                elif a==b:
                    return 0
                else:
                    return 1
            else:
                return len(a)-len(b)
        N = len(nums)
        nums.sort(key=cmp_to_key(cmp))
        return nums[N-k]