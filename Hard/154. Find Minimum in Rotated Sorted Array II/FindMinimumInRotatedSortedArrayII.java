/*
LeetCode Hard: 154. Find Minimum in Rotated Sorted Array II
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Check FindMinimumInRotatedSortedArrayII.cpp for brief solution explanation.
*/
class Solution {
    public int findMin(int[] nums) {
        int N = nums.length;
        int l = 0, r = N-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]>nums[r]){
                l = m+1;
            }else if(nums[m]<nums[r]){
                r = m;
            }else{
                r--;
            }
        }
        return nums[l];
    }
}