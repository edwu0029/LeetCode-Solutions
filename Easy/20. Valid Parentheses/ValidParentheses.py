'''
LeetCode Easy: 20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/

Check ValidParentheses.cpp for brief solution explanation.
'''
class Solution:
    def isValid(self, s: str) -> bool:
        N = len(s)
        m = {'{': 1, '}': 1, '(': 2, ')': 2, '[': 3, ']': 3}
        open_brackets = []
        for i in range(N):
            cur = m[s[i]]
            if s[i] in "{([":
                open_brackets.append(cur)
            else:
                if len(open_brackets)<=0 or open_brackets[-1]!=cur:
                    return False
                else:
                    open_brackets.pop()
        return len(open_brackets)==0