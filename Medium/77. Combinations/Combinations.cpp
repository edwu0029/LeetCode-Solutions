/*
LeetCode Medium: 77. Combinations
https://leetcode.com/problems/combinations/

Brief Solution Explanation:
- We can use a very simple recursive dynamic programming approach to solve this problem
    - let dp(n, k, idx, cur, ans) be used to represent that we have picked K-k numbers already from 1 to idx inclusive
    - n = a constant, the total number
    - k = how many numbers we can pick left currently
    - idx = the current index we are at
    - cur = array/list of the current numbers we have ALREADY picked
    - ans = the final answer array 
    - If k==0, we have reached a base case where we have chose all k numbers:
        - We can simply add cur to ans and return to go back to the previous calls
    - Otherwise, we are now at number idx, we have two choices:
        - 1. Don't pick idx
            - We simply move on to the next idx, dp(n, k, idx+1, cur, ans) 
        - 2. Don't pick idx
            - We must add idx to cur
            - Since we picked idx, we now have to pick one less number (k-1)
            - We can move on to dp(n, k-1, idx+1, cur, ans)
                - Remember that cur now includes idx in it
- We can return the array ans at the end as the final answer
- Alternative Solution:
    - Since N is relatively small, we can use a bitmasking technique to iterate through all possible take/not take
    of 1 to N
    - If there are a total of k bits, we can add that bit mask to the answer array
    - This would result in a O(2^N) time complexity solution

Time Complexity: O(nCk*K)
Memory Complexity: O(nCk*K)
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>cur;
        dp(n, k, 1, cur, ans);
        return ans;
    }
    void dp(int n, int k, int idx, vector<int>&cur, vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(cur);
            return;
        }
        if(idx>n) return;
        dp(n, k, idx+1, cur, ans); //Don't pick idx
        cur.push_back(idx);
        dp(n, k-1, idx+1, cur, ans); //Pick idx
        cur.pop_back();
    }
};