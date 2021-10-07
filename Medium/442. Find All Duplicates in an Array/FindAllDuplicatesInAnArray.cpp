/*
LeetCode Medium: 442. Find All Duplicates in an Array
https://leetcode.com/problems/find-all-duplicates-in-an-array/

Brief Solution Explanation:
N = Length of nums
- As the problem states: You must write an algorithm that runs in O(n) time and uses only constant extra space.
- Since we are limited to O(1) memory, we have to manipulate the original array to keep track of if we have
visited a value or not
- We can use the sign of nums[i] to keep track of the frequency of the values
- If nums[i] is negative, then the number (i+1) has appeared before
    - Remember nums is 0-indexed, which is why we we look at the number (i+1)
    - Ex. If nums[0]<0, then 1 has appeared before
    - Ex. If nums[4]<0, then 5 has appeared before
- We can then simply look through the array for each index i
    - Let cur = abs(nums[i])
    - If nums[cur-1] is positive (not appeared) before, then make it negative (mark as visited)
    - If nums[cur-1] is negative, we have a duplicate, so add cur to your answer list

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int N = nums.size();
        vector<int>ans;
        for(int i = 0;i<N;i++){
            int cur = abs(nums[i]);
            if(nums[cur-1]<0){
                ans.push_back(cur);
            }else{
                nums[cur-1]*=-1;
            }
        }
        return ans;
    }
};