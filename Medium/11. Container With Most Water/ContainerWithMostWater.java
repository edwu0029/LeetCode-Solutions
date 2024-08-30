/*
LeetCode Medium: 11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/description/

Check ContainerWithMostWater.cpp for brief solution explanation.
*/
class Solution {
    public int maxArea(int[] height) {
        int N = height.length;
        int ans = 0, l = 0, r = N-1;
        while(l<=r){
            ans = Math.max(ans, Math.min(height[l], height[r])*(r-l));
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
}