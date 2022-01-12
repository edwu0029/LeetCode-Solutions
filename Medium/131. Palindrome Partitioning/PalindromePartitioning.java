/*
LeetCode Medium: 131. Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/

Check PalindromePartitioning.cpp for brief solution explanation.
*/
class Solution {
    public List<List<String>>ans;
    public boolean check_palindrome(String s){
        for(int i = 0;i<s.length()/2;i++){
            if(s.charAt(i)!=s.charAt(s.length()-i-1)){
                return false;
            }
        }
        return true;
    }
    public void traverse(List<String>cur, String s, int p){
        if(p==s.length()){
            ans.add(cur);
        }else{
            for(int i = p+1;i<=s.length();i++){
                String nxt = s.substring(p, i);
                if(check_palindrome(nxt)){
                    List<String>t = new LinkedList<String>(cur);
                    t.add(nxt);
                    traverse(t, s, i);
                }
            }
        }
    }
    public List<List<String>> partition(String s) {
        ans = new LinkedList<List<String>>();
        List<String>cur = new LinkedList<String>();
        traverse(cur, s, 0);
        return ans;
    }
}