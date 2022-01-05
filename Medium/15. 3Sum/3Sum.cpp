/*
LeetCode Medium: 15. 3Sum
https://leetcode.com/problems/3sum/

Brief Solution Explanation:
N = Length of nums
- This is a very classic problem with many solutions. Here I will describe the O(N^2) solution since it
it works under the constraints of the problem, 0<=N<=3000
- First, let us sort nums in increasing order of value
- We want to find all pairs of (l, m, r) such that nums[l]+nums[m]+nums[r]==0
- Let us begin by fixing the position of l and finding out how many pairs of (m, r) can match with it
    - By rearanging the property, we can determine that nums[m]+nums[r] = -nums[l]
    - Our problem has now simplified to finding all pairs of (m, r) such that l<m<r and nums[m]+nums[r] = -nums[l]
    - We can use a two-pointer approach where m starts at l+1, and r starts at N-1 (0-indexed array)
        - Let sum = nums[m]+nums[r]
        - If sum<need, then we need to move m to the right as our current sum is not large enough
        - If sum>need, then we need to move r to the left as our current sum is too large
        - We don't ever move m to the left or r to the right since if r ever needed to move to the right, it should
        have never been its current position in the first place since nums[r]<=nums[r+1]. Similarily with m.
        - Otherwise, we found a match
            - To prevent overcounting duplicates, we can move m to the right-most position of nums[m]
            and move r to the left-most position of nums[r]
        - This runs in O(N)

- We can loop through all possible positions of l and using the process above, accumulate an answer
    - Remember if there are multiple values of nums[l] that are the same, we only need to process it once

Time Complexity: O(N^2)
Memory Complexity: O(1)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int l = 0;l<N-2;l++){
            int m = l+1, r = N-1;
            while(m<r&&m<N&&r<N){
                int sum = nums[m]+nums[r];
                if(sum<-nums[l]){
                    m++;
                }else if(sum>-nums[l]){
                    r--;
                }else{
                    vector<int>t = {nums[l], nums[m], nums[r]};
                    ans.push_back(t);
                    //If multiple same values of nums[m], keep moving m to the right
                    while(m<r&&nums[m]==t[1]){
                        m++;
                    }
                    //If multiple same values of nums[r], keep moving r to the left
                    while(m<r&&nums[r]==t[2]){
                        r--;
                    }
                }
            }
            //If multiple same values of nums[l], keep moving l to the right
            while(l+1<N-2&&nums[l+1]==nums[l]){
                l++;
            }
        }
        return ans;
    }
};