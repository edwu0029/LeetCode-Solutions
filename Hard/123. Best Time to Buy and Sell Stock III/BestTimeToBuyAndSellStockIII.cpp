/*
LeetCode Hard: 123. Best Time to Buy and Sell Stock III
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 
Brief Solution Explanation:
N = Length of prices
- Since we can only complete at most two transactions, we can do dp on all possible states
- Let dp[i][0] = Maximum profit up to time i with one buy
-     dp[i][1] = Maximum profit up to time i with one buy, one sell
-     dp[i][2] = Maximum profit up to time i with two buys, one sell
-     dp[i][3] = Maximum profit up to time i with two buys, two sells
- We can then loop through each time i froim 0 to N-1 and calcualte each dp[i] value from dp[i-1] values
    - dp[i][0] = max(dp[i-1][0], -prices[i])
        - Don't buy: dp[i-1][0]
        - Buy now at time i: -prices[i]
    - dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i])
        - Don't sell: dp[i-1][1]
        - Sell now at time i: dp[i-1][0]+prices[i]
    - dp[i][2] = max(dp[i-1][2], dp[i-1][1]-prices[i])
    - dp[i][3] = max(dp[i-1][3], dp[i-1][2]+prices[i])
- Since we we can end with making 0, 1, or 2 full transactions(buy and sell), our answer is max(0, dp[N-1][1], dp[N-1][3])
- During our dp transition, current values only depend on the previous row, thus we can use a flip dp array to optimize memory
usage from O(N) to O(1)

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = end(prices)-begin(prices);
        vector<vector<int>>dp = {{-0x3f3f3f3f, 0, -0x3f3f3f3f, 0}, {0, 0, 0, 0}};
        int pre = 0, cur = 1;
        for(int i = 0;i<N;i++){
            dp[cur][0] = max(dp[pre][0], -prices[i]);
            dp[cur][1] = max(dp[pre][1], dp[pre][0]+prices[i]);
            dp[cur][2] = max(dp[pre][2], dp[pre][1]-prices[i]);
            dp[cur][3] = max(dp[pre][3], dp[pre][2]+prices[i]);
            swap(pre, cur);
        }
        return max(0, max(dp[pre][1], dp[pre][3]));
    }
};