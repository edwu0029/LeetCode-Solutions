/*
LeetCode Medium: 1094. Car Pooling
https://leetcode.com/problems/car-pooling/

Check CarPooling.cpp for brief solution explanation.
*/
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int N = trips.length, D = 0;
        for(int i = 0;i<N;i++){
            D = Math.max(D, trips[i][2]+1);
        }
        int[]sum = new int[D+1];
        for(int i = 0;i<N;i++){
            sum[trips[i][1]]+=trips[i][0];
            sum[trips[i][2]]-=trips[i][0];
        }
        for(int i = 0;i<=D;i++){
            if(i>0){
                sum[i]+=sum[i-1];
            }
            if(sum[i]>capacity){
                return false;
            }
        }
        return true;
    }
}