/*
LeetCode Medium: 79. Word Search
https://leetcode.com/problems/word-search/

Check WordSearch.cpp for brief solution explanation.
*/
class Solution {
    int[][]neighbours = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public boolean bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    public boolean dfs(int r, int c, int M, int N, char[][] board, String word, int idx){
        if(idx+1>=word.length()){
            return true;
        }
        char cur = board[r][c];
        board[r][c] = '*';
        boolean res = false;
        for(int i = 0;i<4;i++){
            int newR = r+neighbours[i][0], newC = c+neighbours[i][1];
            if(bounds(newR, newC, M, N)&&board[newR][newC]==word.charAt(idx+1)){
                res|=dfs(newR, newC, M, N, board, word, idx+1);
            }
            if(res){
                return true;
            }
        }
        board[r][c] = cur;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        int M = board.length, N = board[0].length;
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(board[i][j]==word.charAt(0)&&dfs(i, j, M, N, board, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
}