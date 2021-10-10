/*
LeetCode Medium: 201. Bitwise AND of Numbers Range
https://leetcode.com/problems/bitwise-and-of-numbers-range/

Check BitwiseANDofNumbersRange.cpp for brief solution explanation.
*/
class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i = 31;i>=0;i--){
            int l = (((1<<i)&left)>0)?1:0, r = (((1<<i)&right)>0)?1:0;
            if(l==r){
                ans+=l*(1<<i);
            }else{
                break;
            }
        }
        return ans;
    }
}