/*
LeetCode Easy: 485. Max Consecutive Ones
https://leetcode.com/problems/max-consecutive-ones/

Brief Solution Explanation:
N = Length of nums
- Simple greedy apporach, keeping a counter of the best answer and current count for
consecutive ones
- Loop through the array
    - If nums[i] is 1, add 1 to counter and update the answer accordingly
    - If nums[i] is 0, restart the counter

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int N = nums.size(), ans = 0, cnt = 0;
        for(int i = 0;i<N;i++){
            if(nums[i]==1){
                cnt++;
                ans = max(ans, cnt);
            }else{
                cnt = 0;
            }
        }
        return ans;
    }
};