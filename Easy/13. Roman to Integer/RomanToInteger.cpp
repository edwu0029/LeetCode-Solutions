/*
LeetCode Easy: 13. Roman to Integer
https://leetcode.com/problems/roman-to-integer/

Brief Solution Explanation:
N = Length of Roman Numeral/Length of string s
- We will keep track of the current value of the numeral in variable ans
- Loop through the string, keeping track of the previous letter's decimal equivalent in pre_value.
Initially, pre_value can be some arbitrarily large number such as 10,000
    - Let cur_value be the decimal equivalent of the current letter
    - If pre_value<cur_value, we know that we have to subtract the previous value(Ex. IV, we need to subtract I from V since I<V)
        - Thus, we subtract 2*pre_value from ans since we already added pre_value previously
    - We then add cur_value normally

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int romanToInt(string s) {
        map<char, int>legend;
        legend['I'] = 1;
        legend['V'] = 5;
        legend['X'] = 10;
        legend['L'] = 50;
        legend['C'] = 100;
        legend['D'] = 500;
        legend['M'] = 1000;
        int pre_value = 10000, ans = 0;
        for(int i = 0;i<s.size();i++){
            int cur_value = legend[s[i]];
            if(pre_value<cur_value){
                ans-=2*pre_value;
            }
            ans+=cur_value;
            pre_value = cur_value;
        }
        return ans;
    }
};