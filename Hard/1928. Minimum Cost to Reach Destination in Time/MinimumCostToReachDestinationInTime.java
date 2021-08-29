/*
LeetCode Hard: 1928. Minimum Cost to Reach Destination in Time
https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/

Check MinimumCostToReachDestinationInTime.cpp for brief solution explanation.
*/
class Solution {
    public class Edge{
        int v, t;
        Edge(int v, int t){
            this.v = v;
            this.t = t;
        }
    }
    public int minCost(int maxTime, int[][] edges, int[] passingFees) {
        int N = passingFees.length;
        ArrayList<Edge>[]adj = new ArrayList[N];
        for(int i = 0;i<N;i++){
            adj[i] = new ArrayList<Edge>();
        }
        for(int i = 0;i<edges.length;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int t = edges[i][2];
            adj[a].add(new Edge(b, t));
            adj[b].add(new Edge(a, t));
        }
        int[][]dp = new int[maxTime+1][N];
        for(int i = 0;i<=maxTime;i++){
            Arrays.fill(dp[i], 0x3f3f3f3f);
        }
        dp[0][0] = passingFees[0];
        for(int i = 0;i<maxTime;i++){
            for(int j = 0;j<N;j++){
                if(dp[i][j]>=0x3f3f3f3f){
                    continue;
                }
                for(Edge e:adj[j]){
                    int v = e.v, newTime = i+e.t;
                    if(newTime<=maxTime){
                        dp[newTime][v] = Math.min(dp[newTime][v], dp[i][j]+passingFees[v]);
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0;i<=maxTime;i++){
            ans = Math.min(ans, dp[i][N-1]);
        }
        if(ans>=0x3f3f3f3f){
            return -1;
        }else{
            return ans;
        }
    }
}