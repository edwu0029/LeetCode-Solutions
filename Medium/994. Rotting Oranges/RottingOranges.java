/*
LeetCode Medium: 994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/

Check RottingOranges.cpp for brief solution explanation.
*/
class Solution {
    public int orangesRotting(int[][] grid) {
        int M = grid.length, N = grid[0].length;
        Queue<Integer>qr = new LinkedList<Integer>();
        Queue<Integer>qc = new LinkedList<Integer>();
        boolean[][]vis = new boolean[M][N];
        int[][]time = new int[M][N];
        int cnt = 0;
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(grid[i][j]==2){
                    qr.add(i);
                    qc.add(j);
                    vis[i][j]= true;
                }else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int ans = 0;
        int[][]adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!qr.isEmpty()){
            int r = qr.poll(), c = qc.poll();
            ans = time[r][c];
            for(int i = 0;i<4;i++){
                int newR = r+adj[i][0], newC = c+adj[i][1];
                boolean bounds = 0<=newR&&newR<M&&0<=newC&&newC<N;
                if(bounds&&!vis[newR][newC]&&grid[newR][newC]==1){
                    vis[newR][newC] = true;
                    time[newR][newC] = time[r][c]+1;
                    qr.add(newR);
                    qc.add(newC);
                    cnt--;
                }
            }
        }
        if(cnt==0){
            return ans;
        }else{
            return -1;
        }
    }
}