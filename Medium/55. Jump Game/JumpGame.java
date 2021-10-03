/*
LeetCode Medium: 55. Jump Game
https://leetcode.com/problems/jump-game/

Check JumpGame.cpp for brief solution explanation.
*/
class Solution {
    public boolean canJump(int[] nums) {
        int N = nums.length, mx_reachable = 0;
        for(int i = 0;i<N;i++){
            if(mx_reachable<i){
                return false;
            }else{
                mx_reachable = Math.max(mx_reachable, i+nums[i]);
            }
        }
        return true;
    }
}