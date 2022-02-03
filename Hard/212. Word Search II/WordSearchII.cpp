/*
LeetCode Hard: 79. Word Search
https://leetcode.com/problems/word-search/

Brief Solution Explanation:
M = Number of rows
N = Number of columns
L = Maximum word length
S = Sum of length of all words
- This is a extention of the problem 79. Word Search, a medium problem. We will be using a similar approach to do this problem
    - 79. Word Search
    https://leetcode.com/problems/word-search/
- Since we have multiple words to look for, we can build a Trie of all the words
    - To see how to build a Trie, you can take a look at the medium problem 208. Implement Trie
- Similar to Word Search, we will still be using a dfs to find all possible strings of length L
- To check if any of the paths match any of the words, we can use the Trie to check efficiently

Time Complexity: O(M*N*3^L)
Memory Complexity: O(K)
*/
class TrieNode{
public:
    vector<TrieNode*>nxt;
    bool isEnd;
    string word;
    TrieNode(){
        nxt.resize(26);
        isEnd = false;
        word = "";
    }
};

class Solution {
public:
    int M, N;
    vector<vector<int>>adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<string>ans;
    bool bounds(int r, int c){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* cur){
        if(board[r][c]=='*'||cur->nxt[board[r][c]-'a']==NULL){
            return;
        }else{
            cur = cur->nxt[board[r][c]-'a'];
        }
        if(cur->isEnd){
            ans.push_back(cur->word);
            cur->isEnd = false;
        }
        char t = board[r][c];
        board[r][c] = '*';
        for(int i = 0;i<4;i++){
            int newR = r+adj[i][0], newC = c+adj[i][1];
            if(bounds(newR, newC)){
                dfs(newR, newC, board, cur);
            }
        }
        board[r][c] = t;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        M = board.size();
        N = board[0].size();
        //Create Trie
        TrieNode* root = new TrieNode();
        for(int i = 0;i<words.size();i++){
            TrieNode*cur = root;
            for(int j = 0;j<words[i].size();j++){
                if(cur->nxt[words[i][j]-'a']==NULL){
                    cur->nxt[words[i][j]-'a'] = new TrieNode();
                }
                cur = cur->nxt[words[i][j]-'a'];
            }
            cur->isEnd = true;
            cur->word = words[i];
        }
        //DFS
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(root->nxt[board[i][j]-'a']!=NULL){
                    dfs(i, j, board, root);
                }
            }
        }
        return ans;
    }
};