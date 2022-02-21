/*
LeetCode Easy: 169. Majority Element
https://leetcode.com/problems/majority-element/

Brief Solution Explanation:
N = Length of nums
- One thing to note is that there will always be one majority element, but never two
- We can use a map to maintain the frequency of each element as we loop through nums
    - As soon as we find a element with a frequency greater than N/2, then we found our answer

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int>freq;
        int ans = 0;
        for(int i = 0;i<N;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>N/2){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};