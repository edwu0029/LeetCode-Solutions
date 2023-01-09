/*
 * LeetCode Easy: 520. Detect Capital
 * https://leetcode.com/problems/detect-capital/
 * 
 * Check DetectCapital.cpp for brief solution explanation.
 */
class Solution {
    public boolean detectCapitalUse(String word) {
        int N = word.length();
        int capitals = 0;
        for (int i = 0; i < N; i++) {
            if (isCapital(word.charAt(i))) {
                capitals++;
            }
        }
        if (capitals == 0 || capitals == N || (capitals == 1 && isCapital(word.charAt(0)))) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isCapital(char a) {
        return 'A' <= a && a <= 'Z';
    }
}