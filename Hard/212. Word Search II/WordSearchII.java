/*
LeetCode Hard: 212. Word Search II
https://leetcode.com/problems/word-search-ii/

Check WordSearchII.cpp for brief solution explanation.
*/
class TrieNode{
    public TrieNode[]nxt;
    public boolean isEnd;
    public String word;
    public TrieNode(){
        nxt = new TrieNode[26];
        isEnd = false;
        word = "";
    }
}
class Solution {
    public int M, N;
    public int[][]adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public List<String>ans;
    public boolean bounds(int r, int c){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    public void dfs(int r, int c, char[][]board, TrieNode cur){
        if(board[r][c]=='*'||cur.nxt[board[r][c]-'a']==null){
            return;
        }else{
            cur = cur.nxt[board[r][c]-'a'];
        }
        if(cur.isEnd){
            ans.add(cur.word);
            cur.isEnd = false;
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
    public List<String> findWords(char[][] board, String[] words) {
        M = board.length;
        N = board[0].length;
        ans = new LinkedList<String>();
        TrieNode root = new TrieNode();
        for(int i = 0;i<words.length;i++){
            TrieNode cur = root;
            for(int j = 0;j<words[i].length();j++){
                if(cur.nxt[words[i].charAt(j)-'a']==null){
                    cur.nxt[words[i].charAt(j)-'a'] = new TrieNode();
                }
                cur = cur.nxt[words[i].charAt(j)-'a'];
            }
            cur.isEnd = true;
            cur.word = words[i];
        }
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(root.nxt[board[i][j]-'a']!=null){
                    dfs(i, j, board, root);
                }
            }
        }
        return ans;
    }
}