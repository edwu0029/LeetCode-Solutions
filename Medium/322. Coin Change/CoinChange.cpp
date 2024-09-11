/*
LeetCode Medium: 322. Coin Change
https://leetcode.com/problems/coin-change/description/

Brief Solution Explanation:
Let N = Number of coins
Let M = The amount of money we want
- This problem essentially boils down to a knapsack problem, where we want to find the minimum number of coins
to make an amount M, with infinite qunatity of coins
- Let dp[i] = The minimum number of coins to make i
- Intially, dp[0] = 0, since we need 0 coins to make 0
- Now, let us loop coins, with coins[i] being the current coin
  - For each amount j, 0<=j<amount, we can make dp[j+coins[i]] by taking the current coin, coins[i].
  - Thus we can make the dp transition dp[j+coins[i]] = min(dp[j+coins[i]], dp[i]+1)
  - If we loop j from 0 to amount, this dp transition will implicitly take into account the infinite number of coins available
- To check if the amount is possible, we can intially fill the dp with -1, and update accordingly when making dp transitions
  - If a dp[j+coins[i]] is -1, simply make dp[j+coins[i]] = dp[j]+1
- We can return dp[amount] for the final answer

Time Complexity: O(N*M)
Memory Complexity: O(M)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        vector<int>dp(amount+1, -1);
        dp[0] = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<=amount;j++){
                if(dp[j]==-1 || (long long) j+coins[i]>(long long)amount) continue;
                if(dp[j+coins[i]]==-1) dp[j+coins[i]] = dp[j]+1;
                else dp[j+coins[i]] = min(dp[j+coins[i]], dp[j]+1);
            }
        }
        return dp[amount];
    }
};