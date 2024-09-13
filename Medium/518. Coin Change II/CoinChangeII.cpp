/*
LeetCode Medium: 518. Coin Change II
https://leetcode.com/problems/coin-change-ii/

Brief Solution Explanation:
N = Number of coins
M = The amount we want to make
- This problem is very similar to Coin Change (https://leetcode.com/problems/coin-change/description/), but
we want the TOTAL number of combinations to make an amount, instead of the minimum number of coins
- The set up to this problem is the exact same, with two minor changes
  - Our inital condition is dp[0] = 1, since there is 1 way to get 0
  - Since we want the total amount, our dp transition should be adding instead of taking the min
  dp[j+coins[i]] += dp[j]
- See "322. Coin Change" folder for more info 

Time Complexity: O(N*M)
Memory Complexity: O(M)
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<amount;j++){
                if(j+coins[i]>amount) continue;
                dp[j+coins[i]]+=dp[j];
            }
        }
        return dp[amount];
    }
};