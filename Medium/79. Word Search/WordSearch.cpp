/*
LeetCode Medium: 79. Word Search
https://leetcode.com/problems/word-search/

Brief Solution Explanation:
M = Number of rows
N = Number of columns
L = Length of string word
- A simple dfs will allow us to traverse all possible paths of length L, and we can then check if that path has 
the order and letters needed for our desired string
- If so, we can return true and break out of the recursive call
- Remember in the dfs to mark visited squares and unmark them after we are done processing the current square

- When we do the dfs traversal, we will check only paths of at most length L and for each, there are
maximum 3 possible neighbours we move to (4 neighbours - 1 previous neighbour)
Time Complexity: O(M*N*3^L)
Memory Complexity: O(1)
*/
class Solution {
public:
    vector<vector<int>>neighbours = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    bool dfs(int r, int c, int M, int N, vector<vector<char>>& board, string word, int idx){
        if(idx+1>=word.size()){
            return true;
        }
        char cur = board[r][c];
        //Mark current cell as visited
        board[r][c] = '*';
        bool res = false;
        //Check neighbours
        for(int i = 0;i<4;i++){
            int newR = r+neighbours[i][0], newC = c+neighbours[i][1];
            if(bounds(newR, newC, M, N)&&board[newR][newC]==word[idx+1]){
                res|=dfs(newR, newC, M, N, board, word, idx+1);
            }
            if(res){
                return true;
            }
        }
        //Erase visited mark
        board[r][c] = cur;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int M = board.size(), N = board[0].size();
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(board[i][j]==word[0]&&dfs(i, j, M, N, board, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};