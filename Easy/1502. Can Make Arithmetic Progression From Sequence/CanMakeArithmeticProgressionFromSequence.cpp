/*
LeetCode Easy: 1502. Can Make Arithmetic Progression From Sequence
https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

Brief Solution Explanation:
N = Length of array
- An arithmetic progression will always be monotonically increasing or decreasing, allowing us to
sort the array first to put the sequence in correct order
    - Sorting using built in sort functions will run in NlogN
- We can then loop through the array and simply check if the difference between adjacent elements is the same
as diff
    - where diff = arr[1]-arr[0], the difference between elements to be checked
- If all the differences match, return true
- Otherwise, return false

Time Complexity: O(NlogN)
Memory Complexity: O(1)
*/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1]-arr[0];
        for(int i = 2;i<arr.size();i++){
            if(arr[i]-arr[i-1]!=diff){
                return false;
            }
        }
        return true;
    }
};