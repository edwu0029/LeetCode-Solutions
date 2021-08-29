/*
LeetCode Easy: 13. Roman to Integer
https://leetcode.com/problems/roman-to-integer/

Check RomanToInteger.cpp for brief solution explanation.
*/
class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer>legend = new HashMap<Character, Integer>();
        legend.put('I', 1);
        legend.put('V', 5);
        legend.put('X', 10);
        legend.put('L', 50);
        legend.put('C', 100);
        legend.put('D', 500);
        legend.put('M', 1000);
        int pre_value = 10000, ans = 0;
        for(int i = 0;i<s.length();i++){
            int cur_value = legend.get(s.charAt(i));
            if(pre_value<cur_value){
                ans-=2*pre_value;
            }
            ans+=cur_value;
            pre_value = cur_value;
        }
        return ans;
    }
}