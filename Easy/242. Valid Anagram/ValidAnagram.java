/*
LeetCode Easy: 242. Valid Anagram
https://leetcode.com/problems/valid-anagram/description/

Check ValidAnagram.cpp for brief solution explanation.
*/
class Solution {
    public boolean isAnagram(String s, String t) {
        int Ns = s.length();
        int Nt = t.length();
        int[]freqs = new int[26];
        int[]freqt = new int[26];
        if(Ns!=Nt){
           return false; 
        }
        for(int i = 0;i<Ns;i++){
            freqs[s.charAt(i)-'a']++;
            freqt[t.charAt(i)-'a']++;
        }
        for(int i = 0;i<26;i++){
            if(freqs[i]!=freqt[i]){
                return false;
            }
        }
        return true;
    }
}