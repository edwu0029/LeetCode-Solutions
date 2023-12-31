'''
LeetCode Medium: 347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/description/

Check TopKFrequentElements.cpp for brief solution explanation.
'''
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        N = len(nums)
        m = defaultdict(int)
        for i in range(N):
            m[nums[i]]+=1
        freq = []
        for x in m.items():
            freq.append(x)
        def cmp(a, b):
            return a[1]-b[1]
        freq.sort(key=cmp_to_key(cmp))
        ans  = []
        for i in range(1, k+1):
            ans.append(freq[len(freq)-i][0])
        return ans