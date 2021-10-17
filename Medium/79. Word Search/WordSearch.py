'''
LeetCode Medium: 79. Word Search
https://leetcode.com/problems/word-search/

Check WordSearch.cpp for brief solution explanation.
'''
class Solution:
    def bounds(self, r, c) -> bool:
        return 0<=r<self.M and 0<=c<self.N
    def dfs(self, r, c, board, word, idx) -> bool:
        if idx+1>=len(word):
            return True
        cur = board[r][c]
        board[r][c] = '*'
        res = False
        for i in range(4):
            newR, newC = r+self.neighbours[i][0], c+self.neighbours[i][1]
            if self.bounds(newR, newC) and board[newR][newC]==word[idx+1]:
                res|=self.dfs(newR, newC, board, word, idx+1)
            if res:
                return True
        board[r][c] = cur
        return False
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.M, self.N = len(board), len(board[0])
        self.neighbours = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        for i in range(self.M):
            for j in range(self.N):
                if board[i][j]==word[0] and self.dfs(i, j, board, word, 0):
                    return True;
        return False