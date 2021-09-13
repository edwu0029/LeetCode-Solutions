/*
LeetCode Easy: 1991. Find the Middle Index in Array
https://leetcode.com/problems/find-the-middle-index-in-array/

Brief Solution Explanation:
N = Length of nums
- For generality sake, let us assume that nums is 1-indexed
- We can check all possible indexes and check if it is a possible middle index
    - Let us pick an index i, which we are checking
    - We simply need to check if sum of [1:i-1]==sum of [i+1:N]
    - This check can be done in O(1) with prefix sums
- If none exist, we return -1

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int N = nums.size();
        vector<int>prefix(N+1);
        for(int i = 0;i<N;i++){
            prefix[i+1] = nums[i]+prefix[i];
        }
        for(int i = 1;i<=N;i++){
            int lft = prefix[i-1]-prefix[0];
            int rht = prefix[N]-prefix[i];
            if(lft==rht){
                return i-1;
            }
        }
        return -1;
    }
};