/*
LeetCode Easy: 169. Majority Element
https://leetcode.com/problems/majority-element/

Check MajorityElement.cpp for brief solution explanation.
*/
class Solution {
    public int majorityElement(int[] nums) {
        int N = nums.length;
        HashMap<Integer, Integer>freq = new HashMap<Integer, Integer>();
        int ans = 0;
        for(int i = 0;i<N;i++){
            freq.put(nums[i], freq.getOrDefault(nums[i], 0)+1);
            if(freq.get(nums[i])>N/2){
                ans = nums[i];
                return ans;
            }
        }
        return ans;
    }
}