/*
LeetCode Medium: 75. Sort Colors
https://leetcode.com/problems/sort-colors/

Brief Solution Explanation:
N = Length of nums
- This is a classic problem called the Dutch National Flag Problem
https://en.wikipedia.org/wiki/Dutch_national_flag_problem
- The key part is that when sorted, all 0's will be to the left of all 1's, which are all to the left of all 2's
    - Thus, we simply need to force all 0's as far left as possible and all 2's as far right as possible
    - This will automatically make all the 1's in the middle
- Let us keep three pointers, l, m, r
    - l = right most index where we can add a 0
    - r = right most left where we can add a 2
    - m = current index being processed
- As we move through the array, there are three cases for nums[m]:
    1. nums[m]==0:
        - Here we need to move the 0 to index l, so we can simply swap nums[l] and nums[m]
        - Move l to the right for new space to put a 0
        - Move m to the right for next index to process
    2. nums[m]==1:
        - Move m to the right for next index to process
        - Since the 1 is already in the middle, we can just skip it
    3. nums[m]==2:
        - Here we need to move the 2 to index r, so we can simply swap nums[m] and nums[r]
        - Move r to the left for new space to put a 2
        - Move m to the right for next index to process
- We stop when m>r since 1's should always be to the left of 2's
- This sorts the array inplace without extra space

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size();
        int l = 0, m = 0, r = N-1;
        while(m<=r){
            if(nums[m]==0){ 
                swap(nums[l], nums[m]);
                l++;
                m++;
            }else if(nums[m]==2){
                swap(nums[m], nums[r]);
                r--;
            }else{
                m++;
            }
        }
    }
}