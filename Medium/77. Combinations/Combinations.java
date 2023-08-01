/*
LeetCode Medium: 77. Combinations
https://leetcode.com/problems/combinations/

Check Combinations.cpp for brief solution explanation.
*/
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>>ans = new ArrayList<>();
        Stack<Integer>cur = new Stack<>();
        dp(n, k, 1, cur, ans);
        return ans;
    }
    public void dp(int n, int k, int idx, Stack<Integer>cur, List<List<Integer>>ans){
        if(k==0){
            ans.add(new ArrayList<>(cur));
            return;
        }
        if(idx>n){
            return;
        }
        dp(n, k, idx+1, cur, ans);
        cur.add(idx);
        dp(n, k-1, idx+1, cur, ans);
        cur.pop();
    }
}