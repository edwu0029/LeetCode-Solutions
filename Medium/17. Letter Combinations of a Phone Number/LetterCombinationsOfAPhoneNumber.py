'''
LeetCode Medium: 17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Check LetterCombinationsOfAPhoneNumber.cpp for brief solution explanation.
'''
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ans = []
        cur = ""
        comb = {"2": "abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}
        def rec(idx, cur, ans):
            if idx==len(digits):
                if cur!="":
                    ans.append(cur)
                return
            for x in comb[digits[idx]]:
                cur+=x
                rec(idx+1, cur, ans)
                cur = cur[:-1]
        rec(0, cur, ans)
        return ans