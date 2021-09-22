'''
LeetCode Easy: 1275. Find Winner on a Tic Tac Toe Game
https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

Check FindWinnerOnATicTacToeGame.cpp for brief solution explanation.
'''
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        def check(grid) -> bool:
            #Check horizontals
            for i in range(3):
                if grid[i][0]!=' ' and grid[i][0]==grid[i][1]==grid[i][2]:
                    return 1 if grid[i][0]=='X' else 2
            #Check verticals
            for i in range(3):
                if grid[0][i]!=' ' and grid[0][i]==grid[1][i]==grid[2][i]:
                    return 1 if grid[0][i]=='X' else 2
            #Check diagonals
            if grid[0][0]!=' ' and grid[0][0]==grid[1][1]==grid[2][2]:
                return 1 if grid[0][0]=='X' else 2
            if grid[0][2]!=' ' and grid[0][2]==grid[1][1]==grid[2][0]:
                return 1 if grid[0][2]=='X' else 2
            cnt = 0
            for i in range(3):
                for j in range(3):
                    if grid[i][j]!=' ':
                        cnt+=1
            if cnt==9:
                return 3
            return 0
        grid = [[' ' for i in range(3)]for i in range(3)]
        for i in range(len(moves)):
            r, c = moves[i][0], moves[i][1]
            if i%2==0:
                grid[r][c] = 'X'
            else:
                grid[r][c] = 'O'
            if check(grid)!=0:
                break
        q = check(grid)
        if q==0:
            return "Pending"
        elif q==1:
            return "A"
        elif q==2:
            return "B"
        else:
            return "Draw"