/*
LeetCode Medium: 131. Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/

Brief Solution Explanation:
N = Length of s
- Since N is very small(1<=N<=16), we can use a "brute-force" recursve approach
- Let us define some variables to be used in the recursive function traverse:
    - ans = A pointer to the answer vector/list
    - s = The original string(unmodified)
    - p = The index of the where the current recursive call is currently at in s
    - cur = A vector/list containing all previous partitions of s from previous recursive calls, up to 
    index p
- For each recursive call, let us do the following,
    - If we have reached the end of the string s, p==N, then we can stop this recursive call and push
    cur into ans and return
    - Otherwise, we can check all possible next partitions that start at index p. i.e. checking all
    s[p:p], s[p:p+1], s[p:p+2], s[p:p+3], ... s[p:N] to see if they are palindromes
        - For ones that are palindromes and thus valid next partitions, we can add them to a copy of cur
        and further the recursive where we do make this partition
- Finally, we can simply return ans

Time Complexity: O(N*2^N)
Memory Complexity: ?
*/
class Solution {
public:
    bool check_palindrome(string& s){
        for(int i = 0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    void traverse(vector<vector<string>>&ans, vector<string>cur, string& s, int p){
        if(p==s.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 1;i<=s.size()-p;i++){
            //Next possible partition
            string nxt = s.substr(p, i);
            if(check_palindrome(nxt)){ //Check for palindrome
                vector<string>t(cur);
                t.push_back(nxt);
                traverse(ans, t, s, p+i);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>cur;
        traverse(ans, cur, s, 0);
        return ans;
    }
};