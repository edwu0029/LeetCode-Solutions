'''
LeetCode Easy: 1502. Can Make Arithmetic Progression From Sequence
https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

Check CanMakeArithmeticProgressionFromSequence.cpp for brief solution explanation.
'''
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        diff = arr[1]-arr[0]
        for i in range(2, len(arr)):
            if arr[i]-arr[i-1]!=diff:
                return False
        return True