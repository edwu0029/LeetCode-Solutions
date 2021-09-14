/*
LeetCode Medium: 1992. Find All Groups of Farmland
https://leetcode.com/problems/find-all-groups-of-farmland/

Check FindAllGroupsOfFarmland.cpp for brief solution explanation.
*/
class Solution {
    public boolean check_bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    public int[][] findFarmland(int[][] land) {
        int M = land.length, N = land[0].length;
        boolean[][]vis = new boolean[M][N];
        ArrayList<ArrayList<Integer>>ans_list = new ArrayList<ArrayList<Integer>>();
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(vis[i][j]||land[i][j]==0){
                    continue;
                }
                int mnr = i, mnc = j, mxr = i, mxc = j;
                int ti = i;
                while(check_bounds(ti, j, M, N)&&land[ti][j]==1){
                    mxr = ti++;
                }
                int tj = j;
                while(check_bounds(i, tj, M, N)&&land[i][tj]==1){
                    mxc = tj++;
                }
                for(int r = mnr;r<=mxr;r++){
                    for(int c = mnc;c<=mxc;c++){
                        vis[r][c] = true;
                    }
                }
                ArrayList<Integer>t = new ArrayList<Integer>();
                t.add(mnr);
                t.add(mnc);
                t.add(mxr);
                t.add(mxc);
                ans_list.add(t);
            }
        }
        int[][]ans = new int[ans_list.size()][4];
        for(int i = 0;i<ans_list.size();i++){
            for(int j = 0;j<4;j++){
                ans[i][j] = ans_list.get(i).get(j);
            }
        }
        return ans;
    }
}