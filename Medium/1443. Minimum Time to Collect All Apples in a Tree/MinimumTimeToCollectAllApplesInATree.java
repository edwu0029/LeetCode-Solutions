/*
LeetCode Medium: 1443. Minimum Time to Collect All Apples in a Tree
https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

Check MinimumTimeToCollectAllApplesInATree.cpp for brief solution explanation.
*/
class Solution {
    static ArrayList<Integer>[]adj;
    static boolean[]subtreeHasApples;
    static boolean[]vis;
    static int[]sum;

    public int minTime(int N, int[][] edges, List<Boolean> hasApple) {
        adj = new ArrayList[N];
        subtreeHasApples = new boolean[N];
        vis = new boolean[N];
        sum = new int[N];
        for(int i = 0;i<N;i++){
            adj[i] = new ArrayList<Integer>();
        }
        for(int i = 0;i<edges.length;i++){
            adj[edges[i][0]].add(edges[i][1]);
            adj[edges[i][1]].add(edges[i][0]);
        }
        dfs(0, hasApple);
        return sum[0];
    }
    public boolean dfs(int u, List<Boolean> hasApple){
        vis[u] = true;
        if(hasApple.get(u)==true){
            subtreeHasApples[u] = true;
        }
        for(int nxt:adj[u]){
            if(!vis[nxt]){
                boolean t = dfs(nxt, hasApple);
                if(t){
                    sum[u]+=2+sum[nxt];
                }
                subtreeHasApples[u] = subtreeHasApples[u]||t;
            }
        }
        return subtreeHasApples[u];
    }
}