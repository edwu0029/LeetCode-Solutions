'''
LeetCode Easy: 496. Next Greater Element I
https://leetcode.com/problems/next-greater-element-i/

Check NextGreaterElementI.cpp for brief solution explanation.
'''
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stk = []
        m = {}
        for i in nums2:
            while len(stk)>0 and stk[-1]<i:
                m[stk[-1]] = i
                stk.pop()
            stk.append(i)
        ans = []
        for i in nums1:
            if i in m:
                ans.append(m[i])
            else:
                ans.append(-1)
        return ans