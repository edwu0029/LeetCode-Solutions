/*
LeetCode Medium: 208. Implement Trie (Prefix Tree)
https://leetcode.com/problems/implement-trie-prefix-tree/
*/
class TrieNode{
public:
    vector<TrieNode*>nxt;
    bool isEnd;
    TrieNode(){
        nxt.resize(26);
        isEnd = false; //If the current TrieNode is the end of a word or not
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0;i<word.size();i++){
            if(cur->nxt[word[i]-'a']==NULL){
                cur->nxt[word[i]-'a'] = new TrieNode();
            }
            cur = cur->nxt[word[i]-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0;i<word.size();i++){
            if(cur->nxt[word[i]-'a']==NULL){
                return false;
            }
            cur = cur->nxt[word[i]-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0;i<prefix.size();i++){
            if(cur->nxt[prefix[i]-'a']==NULL){
                return false;
            }
            cur = cur->nxt[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */