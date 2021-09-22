/*
LeetCode Easy: 1275. Find Winner on a Tic Tac Toe Game
https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

Check FindWinnerOnATicTacToeGame.cpp for brief solution explanation.
*/
class Solution {
    public int check(char[][]grid){
        //Check horizontals
        for(int i = 0;i<3;i++){
            if(grid[i][0]!=' '&&grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2]){
                return grid[i][0]=='X'?1:2;
            }
        }
        //Check verticals
        for(int i = 0;i<3;i++){
            if(grid[0][i]!=' '&&grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i]){
                return grid[0][i]=='X'?1:2;
            }
        }
        //Check Diagonals
        if(grid[0][0]!=' '&&grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2]){
            return grid[0][0]=='X'?1:2;
        }
        if(grid[0][2]!=' '&&grid[0][2]==grid[1][1]&&grid[1][1]==grid[2][0]){
            return grid[0][2]=='X'?1:2;
        }
        //Check if there is a tie
        int cnt = 0;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(grid[i][j]!=' '){
                    cnt++;
                }
            }
        }
        if(cnt==9){ //All squares are filled
            return 3;
        }
        return 0;
        //Return 0 = Game hasn't ended
        //Return 1 = Player 1 wins
        //Return 2 = Player 2 wins
        //Return 3 = Game ends with a tie
    }
    public String tictactoe(int[][] moves) {
        char[][]grid = new char[3][3];
        //Fill grid with space character
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                grid[i][j] = ' ';
            }
        }
        for(int i = 0;i<moves.length;i++){
            int r = moves[i][0], c = moves[i][1];
            if(i%2==0){
                grid[r][c] = 'X';
            }else{
                grid[r][c] = 'O';
            }
            if(check(grid)!=0){
                break;
            }
        }
        int q = check(grid);
        if(q==0){
            return "Pending";
        }else if(q==1){
            return "A";
        }else if(q==2){
            return "B";
        }else{
            return "Draw";
        }
    }
}