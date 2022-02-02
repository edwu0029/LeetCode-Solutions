/*
LeetCode Medium: 309. Best Time to Buy and Sell Stock with Cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Brief Solution Explanation:
N = Length of prices
- We can use a simple dp approach to solve this problem
- Let buy[i] = The maximum profit up to time i if our last transaction was a buy
- Let sell[i] = The maximum profit up to time i if our last transaction was a sell
- Note that for the dp values above, we can buy/sell, then wait to time i. we don't have to buy/sell directly on time i
- We can then have a very simple dp transition of the following for each time i:
    - buy[i] = max(buy[i-1], sell[i-2]-prices[i])
        - We can either wait(buy[i-1]) or we can buy on time i(sell[i-2]-prices[i])
        - We use sell[i-2] since we have to cooldown one day when we sell before we can buy again
    - sell[i] = max(sell[i-1], buy[i-1]+prices[i])
        - We can either wait(sell[i-1]) or we can sell on time i(buy[i-1]+prices[i])
- Since it is always optimal to end without holding onto a stock, our final answer is sell[N-1]
- Note that in our dp transition, we only need buy[i-1], sell[i-1] and sell[i-2] to do our transition
    - Thus we can simply keep track of these variables and shift then when we move to the next time i
    - This optimizes our memory usage to constant time
    - The code below doesn't use this optimization

Time Complexity: O(N)
Memory Complexity: O(N) but can be optimized to O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if(N==1){
            return 0;
        }
        vector<int>buy(N), sell(N);
        //Intial dp values
        buy[0] = -prices[0];
        buy[1] = max(-prices[0], -prices[1]);
        sell[1] = max(0, prices[1]-prices[0]);
        
        for(int i = 2;i<N;i++){
            buy[i] = max(buy[i-1], sell[i-2]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
        }
        return sell[N-1];
    }
};