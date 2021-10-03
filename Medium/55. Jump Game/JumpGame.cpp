/*
LeetCode Medium: 55. Jump Game
https://leetcode.com/problems/jump-game/

Brief Solution Explanation:
N = Length of nums
- Observation 1: It can be proven that if we CAN reach an index i, we also can reach indexes i-1, i-2, i-3, ..., 2, 1
- Observation 2: Also, if we CAN'T reach an index i, we also can't reach indexes i+1, i+2, i+3, ..., N-2, N-1
- From this, we can loop and keep track of the furthest index we can possibly reach, call this mx_reachable
    - If we ever encounter an index i where mx_reachhable<i, we have reached an unreachable index and thus,
    from observation 2, all other indexes past that index i are also unreachable
    - If this case happens, our answer is false
- Otherwise, our answer is true

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size(), mx_reachable = 0;
        for(int i = 0;i<N;i++){
            if(mx_reachable<i){
                return false;
            }else{
                mx_reachable = max(mx_reachable, i+nums[i]);
            }
        }
        return true;
    }
};