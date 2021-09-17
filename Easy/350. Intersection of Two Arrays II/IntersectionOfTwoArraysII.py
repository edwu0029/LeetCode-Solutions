'''
LeetCode Easy: 350. Intersection of Two Arrays II
https://leetcode.com/problems/intersection-of-two-arrays-ii/

Check IntersectionOfTwoArraysII.cpp for brief solution explanation.
'''
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        N, M = len(nums1), len(nums2)
        freq1, freq2 = {}, {}
        for i in range(N):
            if nums1[i] not in freq1:
                freq1[nums1[i]] = 1
            else:
                freq1[nums1[i]] = freq1[nums1[i]]+1
        for i in range(M):
            if nums2[i] not in freq2:
                freq2[nums2[i]] = 1
            else:
                freq2[nums2[i]] = freq2[nums2[i]]+1
        ans = []
        for i in freq1.keys():
            t1 = freq1[i]
            t2 = 0 if i not in freq2 else freq2[i]
            qty = min(t1, t2)
            for j in range(qty):
                ans.append(i)
        return ans