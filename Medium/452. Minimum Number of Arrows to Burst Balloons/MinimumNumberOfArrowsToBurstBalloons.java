/*
LeetCode Medium: 452. Minimum Number of Arrows to Burst Balloons
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

Check MinimumNumberOfArrowsToBurstBalloons.cpp for brief solution explanation.
*/
class Solution {
    public int findMinArrowShots(int[][] points) {
        int N = points.length;
        if(N==0){
            return 0;
        }
        Arrays.sort(points, (a, b) -> {
            if(a[1]<b[1]){
                return -1;
            }else if(a[1]==b[1]){
                return 0;
            }else{
                return 1;
            }
        });
        int[]cur = points[0];
        int ans = 1;
        for(int i = 1;i<N;i++){
 
            if(cur[1]<points[i][0]){
                ans++;
                cur = points[i];
            }
        }
        return ans;
    }
}