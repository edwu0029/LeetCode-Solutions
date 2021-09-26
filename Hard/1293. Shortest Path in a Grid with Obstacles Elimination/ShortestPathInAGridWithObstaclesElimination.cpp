/*
LeetCode Hard: 1293. Shortest Path in a Grid with Obstacles Elimination
https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

Brief Solution Explanation:
M = Number of rows
N = Number of columns
K = Number of obstacle eliminations allowed
- We can use a 3D BFS to do this problem
- Let dis[r][c][z] = Minimum distance from (0, 0) to (r, c) while elimanting z obstacles
- Since we are using BFS, as soon as we reach the a state at (r, c), that will be our final answer and minimum distance

Time Complexity: O(M*N*K)
Memory Complexity: O(M*N*K)
*/
class Solution {
public:
    bool bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<vector<int>>>dis(M, vector<vector<int>>(N, vector<int>(k+1, 0)));
        vector<vector<vector<bool>>>vis(M, vector<vector<bool>>(N, vector<bool>(k+1, 0)));
        int moves[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; //Up, Down, Left, Right
        queue<array<int, 3>>q;
        q.push({0, 0, 0});
        dis[0][0][0] = 0;
        vis[0][0][0] = true;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur[0], c = cur[1], z = cur[2];
            if(r==M-1&&c==N-1){
                return dis[r][c][z];
            }
            for(int i = 0;i<4;i++){
                int newR = r+moves[i][0], newC = c+moves[i][1];
                if(bounds(newR, newC, M, N)){
                    //Need to elimnate an obstacle
                    if(grid[newR][newC]==1&&z<k&&!vis[newR][newC][z+1]){
                        dis[newR][newC][z+1] = dis[r][c][z]+1;
                        vis[newR][newC][z+1] = true;
                        q.push({newR, newC, z+1});
                    }
                    //Moving to empty square
                    if(grid[newR][newC]==0&&!vis[newR][newC][z]){
                        dis[newR][newC][z] = dis[r][c][z]+1;
                        vis[newR][newC][z] = true;
                        q.push({newR, newC, z});
                    }
                }
            }
        }
        return -1;
    }
};