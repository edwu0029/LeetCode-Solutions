/*
LeetCode Easy: 1189. Maximum Number of Balloons
https://leetcode.com/problems/maximum-number-of-balloons/

Check MaximumNumberOfBalloons.cpp for brief solution explanation.
*/
class Solution {
    public int maxNumberOfBalloons(String text) {
        int N = text.length();
        int[]freq = new int[26];
        for(int i = 0;i<N;i++){
            freq[text.charAt(i)-'a']++;
        }
        int ans = freq['b'-'a'];
        ans = Math.min(ans, freq[0]);
        ans = Math.min(ans, freq['l'-'a']/2);
        ans = Math.min(ans, freq['o'-'a']/2);
        ans = Math.min(ans, freq['n'-'a']);
        return ans;
    }
}