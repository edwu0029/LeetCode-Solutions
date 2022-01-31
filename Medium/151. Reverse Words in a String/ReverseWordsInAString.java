/*
LeetCode Medium: 151. Reverse Words in a String
https://leetcode.com/problems/reverse-words-in-a-string/

Check ReverseWordsInAString.cpp for brief solution explanation.
*/
class Solution {
    public String reverseWords(String s) {
        int N = s.length(), l = N-1, r = N-1;
        String ans = "";
        while(true){
            while(r>=0&&s.charAt(r)==' '){
                l--;
                r--;
            }
            if(l<0||r<0){
                break;
            }
            while(l>=1&&s.charAt(l-1)!=' '){
                l--;
            }
            ans+=s.substring(l, r+1)+" ";
            r = l = l-1;
        }
        return ans.trim();
    }
}