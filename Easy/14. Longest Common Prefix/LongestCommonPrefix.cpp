/*
LeetCode Easy: 14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/

Brief Solution Explanation:
N = Length of strs
- We can do a vertical scan and compare each character by character from left to right
- For the ith character from the left
    - Loop through all strings and check if they have the same ith character from the left
    - If so, we can add this character to our prefix and continue on
    - Otherwise, we can break out of the loop
    - Note: If the ith character doesn't exist in any of the strings, we also need to break out of the loop
- Our answer is the prefix we've accumulated through processing

Time Complexity: O(L), where L is the sum of all characters in all strings
Memory Complexity: O(1)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int i = 0;;i++){
            bool all_same = true;
            char c = ' ';
            for(int j = 0;j<strs.size();j++){
                if(strs[j].size()<=i){
                    all_same = false;
                    break;
                }else if(c==' '){
                    c = strs[j][i];
                }else if(c!=strs[j][i]){
                    all_same = false;
                    break;
                }
            }
            if(!all_same){
                break;
            }
            prefix+=c;
        }
        return prefix;
    }
};