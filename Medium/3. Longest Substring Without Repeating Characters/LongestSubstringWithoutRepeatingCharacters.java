/*
LeetCode Medium: 3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Check LongestSubstringWithoutRepeatingCharacters.cpp for brief solution explanation.
*/
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int N = s.length();
        if(N==0) return 0;
        int l = 0, r = 0, ans = 0;
        HashMap<Character, Integer>freq = new HashMap<Character, Integer>();
        while(l<N){
            while(r<N&&freq.getOrDefault(s.charAt(r), 0)==0){
                freq.put(s.charAt(r), freq.getOrDefault(s.charAt(r), 0)+1);
                r++;
            }
            ans = Math.max(ans, r-l);
            freq.put(s.charAt(l), 0);
            l++;
        }
        ans = Math.max(ans, r-l);
        return ans;
    }
}