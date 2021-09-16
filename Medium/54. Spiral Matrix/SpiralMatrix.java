/*
LeetCode Medium: 54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/

Check SpiralMatrix.cpp for brief solution explanation.
*/
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int M = matrix.length, N = matrix[0].length;
        boolean[][]vis = new boolean[M][N];
        int r = 0, c = 0;
        vis[r][c] = true;
        List<Integer>ans = new LinkedList<Integer>();
        ans.add(matrix[0][0]);
        while(ans.size()!=M*N){
            while(c+1<N&&!vis[r][c+1]){
                vis[r][c+1] = true;
                ans.add(matrix[r][c+1]);
                c++;
            }
            while(r+1<M&&!vis[r+1][c]){
                vis[r+1][c] = true;
                ans.add(matrix[r+1][c]);
                r++;
            }
            while(c-1>=0&&!vis[r][c-1]){
                vis[r][c-1] = true;
                ans.add(matrix[r][c-1]);
                c--;
            }
            while(r-1>=0&&!vis[r-1][c]){
                vis[r-1][c] = true;
                ans.add(matrix[r-1][c]);
                r--;
            }
        }
        return ans;
    }
}