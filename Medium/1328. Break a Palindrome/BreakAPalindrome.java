/*
LeetCode Medium: 1328. Break a Palindrome
https://leetcode.com/problems/break-a-palindrome/

Check BreakAPalindrome.cpp for brief solution explanation.
*/
class Solution {
    public String breakPalindrome(String palindrome) {
        int N = palindrome.length();
        if(N==1){
            return "";
        }
        String ans = "";
        boolean done = false;
        for(int i = 0;i<N/2;i++){
            if(palindrome.charAt(i)!='a'){
                ans = palindrome.substring(0, i)+"a"+palindrome.substring(i+1);
                done = true;
                break;
            }
        }
        if(!done){
            ans = palindrome.substring(0, N-1)+"b";
        }
        return ans;
    }
}