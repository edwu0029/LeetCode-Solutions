/*
LeetCode Easy: 9. Palindrome Number
https://leetcode.com/problems/palindrome-number/

Check PalindromeNumber.cpp for brief solution explanation.
*/
class Solution {
    public boolean isPalindrome(int x) {
        String num = Integer.toString(x);
        int N = num.length();
        for(int i = 0;i<N/2;i++){
            if(num.charAt(i)!=num.charAt(N-i-1)){
                return false;
            }
        }
        return true;
    }
}