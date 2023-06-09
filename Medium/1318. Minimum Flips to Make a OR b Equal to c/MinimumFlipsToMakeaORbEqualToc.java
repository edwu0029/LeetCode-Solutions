/*
LeetCode Medium: 1318. Minimum Flips to Make a OR b Equal to c
https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

Check MinimumFlipsToMakeaORbEqualToc.cpp for brief solution explanation.
*/
class Solution {
    public int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 0;(1<<i)<=Math.max(a, Math.max(b, c));i++){
            int a_i = a&(1<<i);
            int b_i = b&(1<<i);
            int c_i = c&(1<<i);
            if(c_i==0){
                if(a_i>0) count++;
                if(b_i>0) count++;
            }else{
                //one of either a_i and b_i needs to be 1
                if(a_i+b_i==0){
                    count++;
                }
            }
        }
        return count;
    }
}