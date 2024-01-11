/*
LeetCode Medium: 200. Number of Islands
https://leetcode.com/problems/number-of-islands/description/

Brief Solution Explanation:
M = Number of rows in grid
N = Number of cols in grid
- We can use a simple dfs/recursion method to mark all islands in contiguous "groups"
- If grid[i][j] is land, let groups[i][j] represent the group number of that land tile
    - groups[i][j] = 0 means that this land hasn't been assigned a group yet
- We can loop through all 0<=i<M, 0<=j<N, and find any 
    - If we find a land tile that has a group[i][j] = 0, run the dfs/recursion command
- For the dfs command, we can essentially traverse in all 4 directions (up, down, left, right) that are also land tiles
  to mark them as the same group
- Since we keep track of the total number of groups, we can simply return that number

Time Complexity: O(M*N)
Memory Complexity: O(M*N)
*/
class Solution {
public:
    vector<int>x = {0, 0, 1, -1};
    vector<int>y = {1, -1, 0, 0};
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>>groups(M, vector<int>(N, 0));
        int g = 1;
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(groups[i][j]!=0) continue;
                if(groups[i][j]==0&&grid[i][j]=='1'){
                    //Found ungrouped land
                    dfs(grid, groups, i, j, g, M, N);
                    g++;
                }
            }
        }
        return g-1;
    }
    //Mark groups
    void dfs(vector<vector<char>>&grid, vector<vector<int>>&groups, int r, int c, int &group, int &M, int &N){
        groups[r][c] = group;
        for(int i = 0;i<4;i++){
            int nxtr = r+x[i];
            int nxtc = c+y[i];
            bool check = nxtr<M&&nxtc<N&&0<=nxtr&&0<=nxtc;
            if(check&&groups[nxtr][nxtc]==0&&grid[nxtr][nxtc]=='1'){
                dfs(grid, groups, nxtr, nxtc, group, M, N);
            }
        }
    }
};