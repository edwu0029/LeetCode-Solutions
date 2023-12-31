/*
LeetCode Medium: 238. Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/description/

Brief Solution Explanation:
N = Length of nums
- Since we can't use division, we can use prefix & suffix arrays to solve this problem
- Let prefix[i] = Product of all nums[j] such that 0<=j<=i, up to AND including index i
    - For example, prefix[i] = nums[0]*nums[1]* ... *nums[i-1]*nums[i]
- Let suffix[i] = Product of all nums[j] such that i<=j<N, up to AND including index i
    - For example, suffix[i] = nums[i]*nums[i+1]* ... *nums[N-2]*nums[N-1]
- Let ans[i] be the product of all elements in nums except nums[i]
    - You will notice that ans[i] = prefix[i-1]*suffix[i+1]
    - However, you have to keep in mind two corner cases to avoid out of bounds errors:
        - ans[0] = suffix[1]
        - ans[N-1] = prefix[N-2]
- We can loop through all 0<=i<N and calculate each ans[i] using the prefix and suffix arrays
- Finally, we can return ans

Time Complexity: O(N)
Memory Complexity: O(N)
- Space complexity can be reduced to O(1) since we can use the prefix & suffix technique inplace in the ans array
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int>prefix(N), suffix(N), ans(N);
        prefix[0] = nums[0];
        suffix[N-1] = nums[N-1];
        for(int i = 1;i<N;i++){
            prefix[i] = prefix[i-1]*nums[i];
            suffix[N-1-i] = suffix[N-i]*nums[N-1-i];
        }
        ans[0] = suffix[1];
        ans[N-1] = prefix[N-2];
        for(int i = 1;i<N-1;i++){
            ans[i] = prefix[i-1]*suffix[i+1];
        }
        return ans;
    }
};