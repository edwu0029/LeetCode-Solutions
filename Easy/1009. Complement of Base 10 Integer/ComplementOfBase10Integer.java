/*
LeetCode Easy: 1189. Maximum Number of Balloons
https://leetcode.com/problems/maximum-number-of-balloons/

Check ComplementOfBase10Integer.cpp for brief solution explanation.
*/
class Solution {
    public int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int complement = 0;
        for(int i = 0;(1<<i)<=n;i++){
            if(((1<<i)&n)==0){
                complement+=(1<<i);
            }
        }
        return complement;
    }
}