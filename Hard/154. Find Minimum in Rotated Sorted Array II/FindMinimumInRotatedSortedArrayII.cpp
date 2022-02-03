/*
LeetCode Hard: 154. Find Minimum in Rotated Sorted Array II
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 
Brief Solution Explanation:
N = Length of nums
- At a glance, there is a naive solution of simply looping through nums to find the minimum value in O(N) time
- We can use a binary search solution to get a better average time
- Let us start with l = 0 and r = N-1 and m = (l+r)/2, the midpoint between l and r
    - If nums[m]>nums[r], then the minimum must be on the right half of the array
        - Ex. 20, 30, 0, 10, 10, 20
    - If nums[m]<nums[r], then the minimum must be on the left half of the array
        - Ex. 30, 0, 10, 10, 20, 20
    - Otherwise, we can’t tell due to duplicate values in nums, in which case we can just move our right pointer one to the right
- Because of the duplicate values, this algorithm still has a worst run time of O(N) for cases with lots of duplicate values
    - Ex. 1, 1, 1, 2, …, 1, 1, 1, 1, 1, 1, …
    - Despite the worst time, it is still better on average then the naive O(N) solution
 
Time Complexity: O(logN)
Memory Complexity: O(1)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        int l = 0, r = N-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]>nums[r]){ //Min is on right side
                l = m+1;
            }else if(nums[m]<nums[r]){ //Min is on left side
                r = m;
            }else{ //Can't tell due to duplicate values
                r--;
            }
        }
        return nums[l];
    }
};
 

