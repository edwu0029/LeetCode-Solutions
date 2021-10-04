/*
LeetCode Easy: 463. Island Perimeter
https://leetcode.com/problems/island-perimeter/

Brief Solution Explanation:
M = Number of rows
N = Number of columns
- A simple way to tell if a land tile is on the perimeter of the island is to count the
number of water tiles that are neighbouring (Remember that the grid is also surrounded by water)
- If there are no neighbouring water tiles, then thhe land tile is obviously not on the perimeter
- If there is 1 neighbouring water tile, this land tile contributes 1 unit to the perimeter
- If there is 2 neighbouring water tiles, this land tile contributes 2 units to the perimeter,
and so on
-  From this, it can be seen that for some land tile, it contributes a units to the perimeter
where a is the number of neighbouring water tiles

Time Complexity: O(M*N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int bounds(int r, int c, int M, int N){
        return 0<=r&&r<M&&0<=c&&c<N;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>>neighbours = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int perimeter = 0;
        for(int r = 0;r<M;r++){
            for(int c = 0;c<N;c++){
                if(grid[r][c]==0){
                    continue;
                }
                for(int k = 0;k<4;k++){ //Check neighbours
                    int newR = r+neighbours[k][0], newC = c+neighbours[k][1];
                    //Remember that the outside of the grid is also surrounded by water
                    //and to count those "out of bounds" tiles
                    if(!bounds(newR, newC, M, N)||grid[newR][newC]==0){
                        perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};