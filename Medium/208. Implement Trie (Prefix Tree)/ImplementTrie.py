'''
LeetCode Medium: 208. Implement Trie (Prefix Tree)
https://leetcode.com/problems/implement-trie-prefix-tree/
'''
class TrieNode:

    def __init__(self):
        self.nxt = [None for i in range(26)]
        self.isEnd = False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for i in word:
            if cur.nxt[ord(i)-ord('a')]==None:
                cur.nxt[ord(i)-ord('a')] = TrieNode()
            cur = cur.nxt[ord(i)-ord('a')]
        cur.isEnd = True

    def search(self, word: str) -> bool:
        cur = self.root
        for i in word:
            if cur.nxt[ord(i)-ord('a')]==None:
                return False
            cur = cur.nxt[ord(i)-ord('a')]
        return cur.isEnd

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for i in prefix:
            if cur.nxt[ord(i)-ord('a')]==None:
                return False
            cur = cur.nxt[ord(i)-ord('a')]
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)