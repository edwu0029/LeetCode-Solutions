/*
LeetCode Medium: 46. Permutations
https://leetcode.com/problems/permutations/description/

Check Permutations.cpp for brief solution explanation.
*/
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        ArrayList<List<Integer>>ans = new ArrayList<>();
        Stack<Integer>cur = new Stack<Integer>();
        rec(nums, cur, ans);
        return ans;
    }
    public void rec(int[]nums, Stack<Integer>cur, List<List<Integer>>ans){
        if(cur.size()==nums.length){
            ans.add(new ArrayList<>(cur));
            return;
        }
        for(int i = 0;i<nums.length;i++){
            if(nums[i]==-1000) continue;
            int temp = nums[i];
            cur.add(temp);
            nums[i] = -1000; //Mark as already in cur
            rec(nums, cur, ans);
            cur.pop();
            nums[i] = temp;
        }
    }
}