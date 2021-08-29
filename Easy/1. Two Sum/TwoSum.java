/*
LeetCode Easy: 1. Two Sum
https://leetcode.com/problems/two-sum/

Check TwoSum.cpp for brief solution explanation.
*/
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer>m = new HashMap<Integer, Integer>();
        for(int i = 0;i<nums.length;i++){
            m.put(nums[i], i);
        }
        int[]ans = new int[2];
        for(int i = 0;i<nums.length;i++){
            int conjugate = target-nums[i];
            if(m.containsKey(conjugate)&&i!=m.get(conjugate)){
                ans[0] = i;
                ans[1] = m.get(conjugate);
                break;
            }
        }
        return ans;
    }
}