/*
LeetCode Hard: 1293. Shortest Path in a Grid with Obstacles Elimination
https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

Check ShortestPathInAGridWithObstaclesElimination.cpp for brief solution explanation.
*/
class Solution {
    public boolean bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    public int shortestPath(int[][] grid, int k) {
        int M = grid.length, N = grid[0].length;
        int[][][]dis = new int[M][N][k+1];
        boolean[][][]vis = new boolean[M][N][k+1];
        int[][]moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; //Up, Down, Left, Right
        Queue<int[]>q = new LinkedList<int[]>();
        dis[0][0][0] = 0;
        vis[0][0][0] = true;
        q.add(new int[]{0, 0, 0});
        while(!q.isEmpty()){
            int[]cur = q.poll();
            int r = cur[0], c = cur[1], z = cur[2];
            if(r==M-1&&c==N-1){
                return dis[r][c][z];
            }
            for(int i = 0;i<4;i++){
                int newR = r+moves[i][0], newC = c+moves[i][1];
                if(bounds(newR, newC, M, N)){
                    if(grid[newR][newC]==1&&z<k&&!vis[newR][newC][z+1]){
                        dis[newR][newC][z+1] = dis[r][c][z]+1;
                        vis[newR][newC][z+1] = true;
                        q.add(new int[]{newR, newC, z+1});
                    }
                    if(grid[newR][newC]==0&&!vis[newR][newC][z]){
                        dis[newR][newC][z] = dis[r][c][z]+1;
                        vis[newR][newC][z] = true;
                        q.add(new int[]{newR, newC, z});
                    }
                }
            }
        }
        return -1;
    }
}