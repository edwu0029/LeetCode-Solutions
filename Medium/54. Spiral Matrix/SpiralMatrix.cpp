/*
LeetCode Medium: 54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/

Brief Solution Explanation:
M = Number of rows
N = Number of columns
- We can simply simulate the spiral processing.
    - We can continually simulate one “cycle” of going right, going down, going left, and going up until there are no more unvisited squares left
        - Ex. Keep going right until we hit the boundary or visited square. Then go down until we hit the boundary or visited square...
    - For each processed square, mark it as visited and add it to the answer list
    - Keep track of visited and unvisited squares in an array

Time Complexity: O(M*N)
Memory Complexity: O(M*N)
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<bool>>vis(M, vector<bool>(N, false));
        int r = 0, c = 0;
        vis[0][0] = true;
        vector<int>ans = {matrix[0][0]};
        while(ans.size()!=M*N){
            //Moving Right
            while(c+1<N&&!vis[r][c+1]){
                vis[r][c+1] = true;
                ans.push_back(matrix[r][c+1]);
                c++;
            }
            //Moving Down
            while(r+1<M&&!vis[r+1][c]){
                vis[r+1][c] = true;
                ans.push_back(matrix[r+1][c]);
                r++;
            }
            //Moving Left
            while(c-1>=0&&!vis[r][c-1]){
                vis[r][c-1] = true;
                ans.push_back(matrix[r][c-1]);
                c--;
            }
            //Moving Up
            while(r-1>=0&&!vis[r-1][c]){
                vis[r-1][c] = true;
                ans.push_back(matrix[r-1][c]);
                r--;
            }
        }
        return ans;
    }
};