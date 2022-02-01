/*
LeetCode Easy: 121. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Brief Solution Explanation:
N = Length of prices
- Let us keep an array maxx such that maxx[i] = maximum price from time i to time N-1, esentially the maximum price of all
prices[i], prices[i+1], prices[i+2], prices[i+3], ...  prices[N-1]
- We can then loop through all possible i, 0<=i<N-1, and calculate the profit if we were to buy the stock at time i
    - Profit = maxx[i+1]-prices[i]
- Our answer would be the maximum profit we can get

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<int>maxx(N);
        maxx[N-1] = prices[N-1];
        for(int i = N-2;i>=0;i--){
            maxx[i] = max(prices[i],maxx[i+1]);
        }
        int ans = 0;
        for(int i = 0;i<N-1;i++){
            ans = max(ans, maxx[i+1]-prices[i]);
        }
        return ans;
    }
};