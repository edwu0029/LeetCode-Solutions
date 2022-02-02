/*
LeetCode Medium: 75. Sort Colors
https://leetcode.com/problems/sort-colors/

Check SortColors.cpp for brief solution explanation.
*/
class Solution {
    public void sortColors(int[] nums) {
        int N = nums.length;
        int l = 0, m = 0, r = N-1;
        while(m<=r){
            if(nums[m]==0){
                int t = nums[l];
                nums[l] = nums[m];
                nums[m] = t;
                l++;
                m++;
            }else if(nums[m]==2){
                int t = nums[r];
                nums[r] = nums[m];
                nums[m] = t;
                r--;
            }else{
                m++;
            }
        }
    }
}