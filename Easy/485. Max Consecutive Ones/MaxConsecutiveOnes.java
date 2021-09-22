/*
LeetCode Easy: 485. Max Consecutive Ones
https://leetcode.com/problems/max-consecutive-ones/

Check MaxConsecutiveOnes.cpp for brief solution explanation.
*/
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int N = nums.length, ans = 0, cnt = 0;
        for(int i = 0;i<N;i++){
            if(nums[i]==1){
                cnt++;
                ans = Math.max(ans, cnt);
            }else{
                cnt = 0;
            }
        }
        return ans;
    }
}