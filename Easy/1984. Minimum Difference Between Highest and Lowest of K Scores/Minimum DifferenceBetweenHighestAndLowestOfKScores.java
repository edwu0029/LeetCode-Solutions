/*
LeetCode Easy: 1984. Minimum Difference Between Highest and Lowest of K Scores
https://leetcode.com/problems/roman-to-integer/

Check Minimum DifferenceBetweenHighestAndLowestOfKScores.cpp for brief solution explanation.
*/
class Solution {
    public int minimumDifference(int[] nums, int k) {
        int N = nums.length;
        if(N==1){
            return 0;
        }
        Arrays.sort(nums);
        int ans = nums[N-1];
        for(int i = 0;i+k-1<N;i++){
            ans = Math.min(ans, nums[i+k-1]-nums[i]);
        }
        return ans;
    }
}