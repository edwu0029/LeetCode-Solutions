/*
LeetCode Medium: 2352. Equal Row and Column Pairs
https://leetcode.com/problems/equal-row-and-column-pairs/

Brief Solution Explanation:
N = Number of rows in grid = Number of columns in grid
- We can use a rolling hash technique to generate a hash value for each of the rows and each of the columns
    - We can arbitrarily pick some prime number for our seed and mod values for simplicity
    - More info on rolling hash can be found here: 
        - https://cp-algorithms.com/string/string-hashing.html
    - In my solutions, I use SEED = 131, MOD = 1e9+7
- Generating all the hashes will take O(N^2) time
- Once the hashes have been calcualted, we can simply loop through all possible (row i, col j) combinations
    - For some row i and row j, we simply need to check if row_hash[i]==col_hash[j] to determine if they are equal
        - Since this is essentially only comparing numbers, this comparison is O(1)

- Alternatively, a brute force solution where we check all possible row and column pairs, then 
checks if each of said row and columns are identical using a for loop will also work
    - This would run in O(N^3), which is fast enough given that 1<=N<=200

Time Complexity: O(N^2)
Memory Complexity: O(N)
*/
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int N = grid.size();
        int SEED = 131;
        int MOD = 1e9+7;
        vector<long long>row_hash(N);
        //Create hash for rows
        for(int r = 0;r<N;r++){
            for(int i = 0;i<N;i++){
                row_hash[r] = ((row_hash[r]*SEED)%MOD+grid[r][i-1])%MOD;
            }
        }
        vector<long long>col_hash(N);
        //Create hash for cols
        for(int c = 0;c<N;c++){
            for(int i = 0;i<N;i++){
                col_hash[c] = ((col_hash[c]*SEED)%MOD+grid[i-1][c])%MOD;
            }
        }
        //Check all row and column pairs
        int ans = 0;
        for(int r = 0;r<N;r++){
            for(int c = 0;c<N;c++){
                if(row_hash[r]==col_hash[c]){
                    ans++;
                }
            }
        }
        return ans;
    }
};