/*
LeetCode Hard: 312. Burst Balloons
https://leetcode.com/problems/burst-balloons/

Brief Solution Explanation:
N = Length of nums
- We can use a interval dp approach to solve this problem
- Let dp[l][r] = The maximum coins you can collect by bursting all the balloons in the interval [l, r]
- To make things easier, we can insert 1 to the front and end of nums to generalize the dp transition with the
out of bounds rule
- Let us solve dp states in order of length, starting with intervals of length 1 all the way to intervals of length N
- For some dp[l][r], let us do the following transition
    - Let us pick some index m such that l<=m<r
    - This allows us to "split" the interval and combine the answers as if we remove all balloons in [l, m-1] then remove
    all balloons in [m+1, r], then remove the balloon at m
        - It is guranteed we have already found dp[l][m] and dp[m+1][r] already since we solve dp states in order of length
        - [l, m-1] and [m+1, r] is always smaller in length than [l, r], the interval for the current dp state we are solving
        - dp[l][r] = dp[l][m-1]+dp[m+1][r]+(nums[l-1]*nums[m]*nums[r+1])
        - Note that m-1 and m+1 may go out of bounds, in which the dp[l][m-1] and/or dp[m+1][r] would be 0
    - We can do this for all possible m, l<=m<r
- Our final answer is dp[1][N], the maximium coins to burst all balloons

Time Complexity: O(N^3)
Memory Complexity: O(N^2)
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.insert(nums.begin(), 1); //Add 1 to the front
        nums.insert(nums.end(), 1); //Add 1 to the end
        vector<vector<int>>dp(N+1, vector<int>(N+1));
        for(int len = 1;len<=N;len++){
            for(int l = 1;l<=N-len+1;l++){
                int r = l+len-1;
                for(int m = l;m<=r;m++){
                    int res = nums[l-1]*nums[m]*nums[r+1];
                    if(l<=m-1){
                        res+=dp[l][m-1];
                    }
                    if(m+1<=r){
                        res+=dp[m+1][r];
                    }
                    dp[l][r] = max(dp[l][r], res);
                }
            }
        }
        return dp[1][N];
    }
};