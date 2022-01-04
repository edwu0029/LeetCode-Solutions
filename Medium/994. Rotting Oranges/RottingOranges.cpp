/*
LeetCode Medium: 994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/

Brief Solution Explanation:
- We can use a graph traversal algorithm to solve this problem. I will use BFS(Breadth First Search).
- Let our intial queue contain all the intially rotten oranges and run a BFS.
    - The "distance" in our case represents the time it takes for that orange to be rotten
        - time[i][j] = Time for the orange at (i, j) to become rotten
    - Once the reach a orange in our BFS, we can decrement the total number of fresh oranges left
    - Also keep track of the highest time currently in ans
- Once the BFS is completed, we first need to check if there are any fresh oranges left, if so, return -1
- Otherwise, we return our ans

Time Complexity: O(NM)
Memory Complexity: O(NM)
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<bool>>vis(M, vector<bool>(N, 0));
        vector<vector<int>>time(M, vector<int>(N, 0));
        int cnt = 0;
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i, j));
                    vis[i][j] = true;
                }else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        vector<vector<int>>adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur.first, c = cur.second;
            ans = time[r][c];
            for(int i = 0;i<4;i++){
                int newR = r+adj[i][0], newC = c+adj[i][1];
                bool bounds = 0<=newR&&newR<M&&0<=newC&&newC<N;
                if(bounds&&!vis[newR][newC]&&grid[newR][newC]==1){
                    vis[newR][newC] = true;
                    time[newR][newC] = time[r][c]+1;
                    cnt--;
                    q.push(make_pair(newR, newC));
                }
            }
        }
        if(cnt==0){
            return ans;
        }else{
            return -1;
        }
    }
};