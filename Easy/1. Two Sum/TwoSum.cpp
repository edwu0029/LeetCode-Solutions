/*
LeetCode Easy: 1. Two Sum
https://leetcode.com/problems/two-sum/

Brief Solution Explanation:
N = Length of nums array
- Use a map to keep track of the last index that each value in the array appears in
- Loop through nums, for each index i:
    - Calcualte the conjugate for nums[i]: conjugate = target-nums[i]
    - Using the map, check if the conjugate exists and the index of the conjugate is not the same as i
    - If so, a solution is found

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]] = i+1;
        }
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            int conjugate = target-nums[i];
            if(m[conjugate]!=0&&i+1!=m[conjugate]){
                ans.push_back(i);
                ans.push_back(m[conjugate]-1);
                break;
            }
        }
        return ans;
    }
};