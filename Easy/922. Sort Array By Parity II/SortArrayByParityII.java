/*
LeetCode Easy: 922. Sort Array By Parity II
https://leetcode.com/problems/sort-array-by-parity-ii/

Check SortArrayByParityII.cpp for brief solution explanation.
*/
class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int N = nums.length;
        int i = 0, j = 1;
        while(i<N&&j<N){
            while(i<N&&nums[i]%2==0){
                i+=2;
            }
            while(j<N&&nums[j]%2==1){
                j+=2;
            }
            if(i<N&&j<N){
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }else if(i>=N||j>=N){
                break;
            }
        }
        return nums;
    }
}