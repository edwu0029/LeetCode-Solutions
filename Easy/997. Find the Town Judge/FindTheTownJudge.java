/*
LeetCode Easy: 997. Find the Town Judge
https://leetcode.com/problems/find-the-town-judge/

Check FindTheTownJudge.cpp for brief solution explanation.
*/
class Solution {
    public int findJudge(int n, int[][] trust) {
        int[]in = new int[n+1], out = new int[n+1];
        int T = trust.length;
        for(int i = 0;i<T;i++){
            int a = trust[i][0], b = trust[i][1];
            out[a]++;
            in[b]++;
        }
        for(int i = 1;i<=n;i++){
            if(out[i]==0&&in[i]==n-1){
                return i;
            }
        }
        return -1;
    }
}