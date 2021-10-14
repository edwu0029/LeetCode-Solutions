/*
LeetCode Medium: 279. Perfect Squares
https://leetcode.com/problems/perfect-squares/

Brief Solution Explanation:
- We can use a unbounded knapsack(We can have repetition of items) to solve this problem
https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/
- In this case, our "items" are 1*1 = 1, 2*2 = 4, 3*3 = 9, ..., k*k where k*k is the largest perfect square <= N
- In total, there are sqrt(N) total "items"
- Our knapsack weight is N
- Since we are looking for the least number of perfect square numbers that sum to n, our dp array is intially
filled with infinity(0x3f3f3f3f) with dp[0] = 0 as intial state

Time Complexity: O(N*sqrt(N))
Memory Complexity: O(N)
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 1;i*i<=n;i++){
            for(int j = 0;j<n;j++){
                if(j+i*i<=n) dp[j+i*i] = min(dp[j+i*i], dp[j]+1);
            }
        }
        return dp[n];
    }
};