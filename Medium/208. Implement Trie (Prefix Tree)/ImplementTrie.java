/*
LeetCode Medium: 208. Implement Trie (Prefix Tree)
https://leetcode.com/problems/implement-trie-prefix-tree/
*/
class TrieNode{
    public TrieNode[]nxt;
    public boolean isEnd;
    public TrieNode(){
        nxt = new TrieNode[26];
        isEnd = false;
    }
}

class Trie {
    public TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode cur = root;
        for(int i = 0;i<word.length();i++){
            if(cur.nxt[word.charAt(i)-'a']==null){
                cur.nxt[word.charAt(i)-'a'] = new TrieNode();
            }
            cur = cur.nxt[word.charAt(i)-'a'];
        }
        cur.isEnd = true;
    }
    
    public boolean search(String word) {
        TrieNode cur = root;
        for(int i = 0;i<word.length();i++){
            if(cur.nxt[word.charAt(i)-'a']==null){
                return false;
            }
            cur = cur.nxt[word.charAt(i)-'a'];
        }
        return cur.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode cur = root;
        for(int i = 0;i<prefix.length();i++){
            if(cur.nxt[prefix.charAt(i)-'a']==null){
                return false;
            }
            cur = cur.nxt[prefix.charAt(i)-'a'];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */