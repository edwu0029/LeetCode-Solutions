/*
LeetCode Easy: 922. Sort Array By Parity II
https://leetcode.com/problems/sort-array-by-parity-ii/

Brief Solution Explanation:
N = Length of nums
- Simple implementation by collecting all even elements and odd elements
- Then reconstruct the array with putting an element with the appropriate parity in

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int N = nums.size();
        vector<int>evens, odds;
        for(int i = 0;i<N;i++){
            if(nums[i]%2==0){
                evens.push_back(nums[i]);
            }else{
                odds.push_back(nums[i]);
            }
        }
        vector<int>ans;
        int p1 = 0, p2 = 0;
        for(int i = 0;i<N;i++){
            if(i%2==0){
                ans.push_back(evens[p1++]);
            }else{
                ans.push_back(odds[p2++]);
            }
        }
        return ans;
    }
};