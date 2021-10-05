/*
LeetCode Easy: 70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/

Check ClimbingStairs.cpp for brief solution explanation.
*/
class Solution {
    public int climbStairs(int n) {
        int a = 1, b = 1, c = 0;
        for(int i = 2;i<=n;i++){
            c = a+b;
            a = b;
            b = c;
            c = 0;
        }
        return b;
    }
}