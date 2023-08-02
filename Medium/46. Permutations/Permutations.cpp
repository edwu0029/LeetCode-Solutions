/*
LeetCode Medium: 46. Permutations
https://leetcode.com/problems/permutations/description/

Brief Solution Explanation:
N = Length of nums
- Since N is relatively small (1<=N<=6), we simply need to brute force generate all permutations
- This can be done using a simple recursion technique
  - We can "pick" numbers from nums (without repeat) in any order until we have picked all N numbers, this generates ONE permutation of nums
  - We can essentially simulate this "picking" process to generate all nPn permutations
- Let rec(nums, cur, ans) be used to represent the current state, where the nums array itself will keep track of available and already
  selected numbers
    - nums = array/list of the remaining numbers
        - the number -1000 will be used to mark if a number is already in the cur
        - For example, if nums[i]==-1000, then we know nums[i] has already been selected
        - If nums[j]!=-1000, then nums[j] is still available and must still be put into cur
    - cur = the current numbers already selected in the permutation currently
    - ans = the final answer array/list
    - For each iteration of rec, we can loop through nums for all i from 1 to N:
      - If nums[i]==-1000, we can continue
      - If nums[i]!=-1000, we can try to "choose" this number now
        - Insert nums[i] to the back of cur
        - Mark nums[i]=-1000 as already in cur
        - Call rec(nums, cur, ans) to further the recursion call for "if we picked nums[i] now"
        - We must revert now revert the previous actions to prevent affecting future rec calls
            - Pop from the back of cur to remove nums[i]
            - Reset nums[i] back to its original value
    - For the base case of rec, we have picked all numbers when the size of cur == the size of nums,
      - We can then just add a copy of cur into ans and return
- In the end, all the permutations will be stored in ans
- We can return ans as our final answer

Time Complexity: O(nPn)
Memory Complexity: O(nPn)
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cur;
        rec(nums, cur, ans);
        return ans;
    }
    void rec(vector<int>&nums, vector<int>cur, vector<vector<int>>&ans){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==-1000) continue;
            int temp = nums[i];
            cur.push_back(temp);
            nums[i] = -1000; //Mark as already in cur
            rec(nums, cur, ans);
            cur.pop_back();
            nums[i] = temp;
        }
    }
}; 