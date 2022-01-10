/*
LeetCode Easy: 67. Add Binary
https://leetcode.com/problems/add-binary/

Check AddBinary.cpp for brief solution explanation.
*/
class Solution {
    public String addBinary(String a, String b) {
        if(a.length()<b.length()){
            String t = a;
            a = b;
            b = t;
        }
        a = new StringBuilder(a).reverse().toString();
        b = new StringBuilder(b).reverse().toString();
        String ans = "";
        int carry = 0;
        for(int i = 0;i<a.length();i++){
            int cur = carry+(a.charAt(i)-'0');
            if(i<b.length()){
                cur+=(b.charAt(i)-'0');
            }
            carry = cur/2;
            ans+=(char)((cur%2)+'0');
        }
        if(carry>0){
            ans+=(char)(carry+'0');
        }
        return new StringBuilder(ans).reverse().toString();
    }
}