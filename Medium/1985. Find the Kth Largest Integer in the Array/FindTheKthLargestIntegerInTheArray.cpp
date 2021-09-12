/*
LeetCode Medium: 1985. Find the Kth Largest Integer in the Array
https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

Brief Solution Explanation:
N = Length of nums
- Since the numbers can have up to 100 digits, this is far too large to simply store in a primitive data type and sort normally. Thus
we have to store them as strings
- We can first sort the numbers by their length
    - Since there are no leading zeros, the larger the length of the number, the larger its value will be
- If two numbers have the same length, we can simply compare them lexicographically, which is default for comparing strings
- Our answer will be nums[N-k], the Kth largest number

Time Complexity: O(NlogN)
Memory Complexity: O(1)
*/
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int N = nums.size();
        sort(nums.begin(), nums.end(), [](string a, string b){
            if(a.size()==b.size()){
                return a<b;
            }else{
                return a.size()<b.size();
            }
        });
        return nums[N-k];
    }
};