/*
LeetCode Easy: 217. Contains Duplicate
https://leetcode.com/problems/contains-duplicate/

Brief Solution Explanation:
N = Length of nums
- We can use a map to maintain the frequency of each value in nums
    - Map update and insert are O(1)
- Loop through nums and if the frequency of nums[i] is already in the map, return true
- Otherwise, return false once loop ends

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, bool>freq;
        for(int i = 0;i<N;i++){
            if(!freq[nums[i]]){
                freq[nums[i]] = 1;
            }else{
                return true;
            }
        }
        return false;
    }
};
