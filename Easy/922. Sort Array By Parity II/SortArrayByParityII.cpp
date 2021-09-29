/*
LeetCode Easy: 922. Sort Array By Parity II
https://leetcode.com/problems/sort-array-by-parity-ii/

Brief Solution Explanation:
N = Length of nums
- We can use a simple two pointer to solve this problem
- Given that there are equal amounts of even and odd numbers, we know that for every
misplaced even, there is also a misplaced odd (and vice versa)
- Since the misplaced elements come in pairs, we can just use two pointers to continually find pairs
of misplaced elements and swap them
- Finally we can just return the nums array

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int N = nums.size();
        int i = 0, j = 1;
        while(i<N&&j<N){
            while(i<N&&nums[i]%2==0){
                i+=2;
            }
            while(j<N&&nums[j]%2==1){
                j+=2;
            }
            if(i<N&&j<N){
                swap(nums[i], nums[j]);
            }else if(i>=N||j>=N){ //One of our pointers has reached the end
                //No more misplaced elements
                break;
            }
        }
        return nums;
    }
};