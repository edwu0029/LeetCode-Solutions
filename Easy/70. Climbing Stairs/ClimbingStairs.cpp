/*
LeetCode Easy: 70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/

Brief Solution Explanation:
N = Number of stairs
- We can use a dynamic programming approach to do this problem
- Let dp[i] = Number of ways to reach the ith step
- Our base cases are:
    - dp[0] = 1, there is only one way to get to step 0 (base of stairs)
    - dp[1] = 1, there is only one way to get to step 1 (Step 0 -> Step 1)
- For all dp[i] where 2<=i<=N:
    - Since we can only make steps of length 1 and 2, we can use dp[i-1] and dp[i-2]
    to find our current dp[i]
    - dp transition: dp[i] = dp[i-1]+dp[i-2]
- Our final answer is dp[N]
- Since to find any dp[i], we only need the dp[i-1], and dp[i-3], we can reduce memory to O(1),
by just keeping track of these 3 values for each i

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c = 0;
        //a = dp[i-2], b = dp[i-1], c = dp[i]
        for(int i = 2;i<=n;i++){
            c = a+b;
            //Swap values for next i
            a = b;
            b = c;
            c = 0;
        }
        return b;
    }
};