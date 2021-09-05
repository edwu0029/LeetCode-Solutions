'''
LeetCode Medium: 1980. Find Unique Binary String
https://leetcode.com/problems/find-unique-binary-string/

Check FindUniqueBinaryString.cpp for brief solution explanation.
'''
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        N = len(nums)
        ans = ""
        for mask in range(1<<N):
            cur = ""
            for i in range(N):
                if mask&(1<<i):
                    cur = "1"+cur
                else:
                    cur = "0"+cur
            check = True
            for i in range(N):
                if cur==nums[i]:
                    check = False
                    break
            if check:
                ans = cur
                break
        return ans