/*
LeetCode Easy: 1979. Find Greatest Common Divisor of Array
https://leetcode.com/problems/find-greatest-common-divisor-of-array/

Check FindGreatestCommonDivisorOfArray.cpp for brief solution explanation.
*/
class Solution {
    public int gcd(int a, int b){
        if(b==0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }
    public int findGCD(int[] nums) {
        int N = nums.length;
        int max_num = -1, min_num = 1005;
        for(int i = 0;i<N;i++){
            max_num = Math.max(max_num, nums[i]);
            min_num = Math.min(min_num, nums[i]);
        }
        return gcd(max_num, min_num);
    }
}