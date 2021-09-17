/*
LeetCode Easy: 14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/

Check LongestCommonPrefix.cpp for brief solution explanation.
*/
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String prefix = "";
        for(int i = 0;;i++){
            boolean all_same = true;
            char c = ' ';
            for(int j = 0;j<strs.length;j++){
                if(strs[j].length()<=i){
                    all_same = false;
                    break;
                }else if(c==' '){
                    c = strs[j].charAt(i);
                }else if(c!=strs[j].charAt(i)){
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
}