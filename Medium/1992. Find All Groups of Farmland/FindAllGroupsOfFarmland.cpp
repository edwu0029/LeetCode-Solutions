/*
LeetCode Medium: 1992. Find All Groups of Farmland
https://leetcode.com/problems/find-all-groups-of-farmland/

Brief Solution Explanation:
M = Number of rows
N = Number of columns
- An important thing to note is that all groups are rectangles and to represent these groups, we need
the coordinates of the top-left and bottom-right squares
- We can traverse the 2D land array and once we encounter a unvisited farmland square, we can fix this
as the top-left corner of a new group
    - To find the bottom-right corner of this new group, we can greedily loop down the column until we meet a non-land square, giving
    us the row number of the bottom-right corner
    - Similarly, we do the same but rightward to find the column number of the bottom-right corner
    - With this, we now have the coordinates of hte bottom-right square and can represent this group
    - Finally, we can mark all squares of this group as visited to prevent overprocessing

Time Complexity: O(M*N)
Memory Complexity: O(M*N)
*/
class Solution {
public:
    bool check_bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int M = land.size(), N = land[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>vis(M, vector<bool>(N));
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(vis[i][j]||land[i][j]==0){
                    continue;
                }
                int mnr = i, mnc = j, mxr = i, mxc = j;
                int ti = i;
                //Find row number of bottom-righ corner
                while(check_bounds(ti, j, M, N)&&land[ti][j]==1){
                    mxr = ti++;
                }
                int tj = j;
                //Find column number of bottom-righ corner
                while(check_bounds(i, tj, M, N)&&land[i][tj]==1){
                    mxc = tj++;
                }
                //Mark all squares in this group as visited
                for(int r = mnr;r<=mxr;r++){
                    for(int c = mnc;c<=mxc;c++){
                        vis[r][c] = true;
                    }
                }
                ans.push_back({mnr, mnc, mxr, mxc});
            }
        }
        return ans;
    }
};