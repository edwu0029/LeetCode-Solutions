/*
LeetCode Medium: 442. Find All Duplicates in an Array
https://leetcode.com/problems/find-all-duplicates-in-an-array/

Check FindAllDuplicatesInAnArray.cpp for brief solution explanation.
*/
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int N = nums.length;
        List<Integer>ans = new LinkedList<Integer>();
        for(int i = 0;i<N;i++){
            int cur = Math.abs(nums[i]);
            if(nums[cur-1]<0){
                ans.add(cur);
            }else{
                nums[cur-1]*=-1;
            }
        }
        return ans;
    }
}