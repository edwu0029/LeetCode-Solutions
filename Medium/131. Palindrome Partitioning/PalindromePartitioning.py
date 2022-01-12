'''
LeetCode Medium: 131. Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/

Check PalindromePartitioning.cpp for brief solution explanation.
'''
class Solution:
    def check_palindrome(self, s) -> bool:
        for i in range(len(s)//2):
            if s[i]!=s[len(s)-i-1]:
                return False
        return True

    def traverse(self, cur, s, p):
        if p==len(s):
            self.ans.append(cur)
            return None
        for i in range(p+1, len(s)+1):
            nxt = s[p:i]
            if self.check_palindrome(nxt)==True:
                t = cur.copy()
                t.append(nxt)
                self.traverse(t, s, i)

    def partition(self, s: str) -> List[List[str]]:
        self.ans = []
        cur = []
        self.traverse(cur, s, 0)
        return self.ans