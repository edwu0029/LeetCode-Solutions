'''
LeetCode Hard: 79. Word Search
https://leetcode.com/problems/word-search/

Check WordSearchII.cpp for brief solution explanation.
'''
class TrieNode:
    def __init__(self):
        self.nxt = [None for i in range(26)]
        self.isEnd = False
        self.word = ""

class Solution:
    def dfs(self, r, c, board, cur, length):
        if board[r][c]=='*' or cur.nxt[ord(board[r][c])-ord('a')]==None or length>self.L:
            return
        else:
            cur = cur.nxt[ord(board[r][c])-ord('a')]
        if cur.isEnd:
            self.ans.append(cur.word)
            cur.isEnd = False
        t = board[r][c]
        board[r][c] = '*'
        for dr, dc in self.adj:
            newR, newC = r+dr, c+dc
            if 0<=newR<self.M and 0<=newC<self.N:
                self.dfs(newR, newC, board, cur, length+1)
        board[r][c] = t

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.M = len(board)
        self.N = len(board[0])
        self.L = 0
        self.ans = []
        self.adj = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        root = TrieNode()
        for i in range(len(words)):
            cur = root
            for j in words[i]:
                if cur.nxt[ord(j)-ord('a')]==None:
                    cur.nxt[ord(j)-ord('a')] = TrieNode()
                cur = cur.nxt[ord(j)-ord('a')]
            cur.isEnd = True
            cur.word = words[i]
            self.L = max(self.L, len(words[i]))
        for i in range(self.M):
            for j in range(self.N):
                if root.nxt[ord(board[i][j])-ord('a')]!=None:
                    self.dfs(i, j, board, root, 1)
        return self.ans