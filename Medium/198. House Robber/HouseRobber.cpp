/*
LeetCode Medium: 198. House Robber
https://leetcode.com/problems/house-robber/description/

Brief Solution Explanation:
N = Length of nums
- We can use a very simple dp apporach to solve this problem
- Let dp[i] = Maxmimum amount of money we can steal from houses 1, 2, ..., i
    - Note that we will treat houses as starting from 1 for simplicity sake
- Intially, dp[1] = nums[0]
- To calculate dp[i], we need to consider 2 cases
    1. We rob house i
        - If we rob house i, we must also NOT rob house i-1 to ensure the adjacency rule
        - dp[i-2] is the best answer without robbing house i-1
        - This results in dp[i-2]+nums[i-1]
    2. We don't rob house i
        - This results in dp[i-1]
    - We can take the maximum from these 2 choices for dp[i], in other words
    dp[i] = max(dp[i-1], dp[i-2]+nums[i-1])
- Our final answer is dp[N], the maximum money we can steal from all 1, 2, ..., N houses
Time Complexity: O(N)
Memory Complexity: O(N)
- Can be reduced to O(1) since we only need to keep track of dp[i-2] and dp[i-1], for each i
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int>dp(N+1);
        dp[1] = nums[0];
        for(int i = 2;i<=N;i++){
            dp[i] = max(dp[i-1], nums[i-1]+dp[i-2]);
        }
        return dp[N];
    }
};
