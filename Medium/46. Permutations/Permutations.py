'''
LeetCode Medium: 46. Permutations
https://leetcode.com/problems/permutations/description/

Check Permutations.cpp for brief solution explanation.
'''
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        cur = []
        def rec(nums, cur, ans):
            if len(cur)==len(nums):
                ans.append(cur[:])
                return
            for i in range(0, len(nums)):
                if nums[i]==-1000:
                    continue
                else:
                    temp = nums[i]
                    nums[i]=-1000
                    cur.append(temp)
                    rec(nums, cur, ans)
                    cur.pop()
                    nums[i]=temp
        rec(nums, cur, ans)
        return ans