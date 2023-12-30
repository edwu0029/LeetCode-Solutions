/*
LeetCode Easy: 217. Contains Duplicate
https://leetcode.com/problems/contains-duplicate/

Check ContainsDuplicate.cpp for brief solution explanation.
*/
class Solution {
    public boolean containsDuplicate(int[] nums) {
        int N = nums.length;
        HashMap<Integer, Boolean>freq = new HashMap<Integer, Boolean>();
        for(int i = 0;i<N;i++){
            if(!freq.containsKey(nums[i])){
                freq.put(nums[i], true);
            }else{
                return true;
            }
        }
        return false;
    }
}