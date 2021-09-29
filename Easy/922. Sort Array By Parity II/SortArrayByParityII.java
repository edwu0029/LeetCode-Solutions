/*
LeetCode Easy: 922. Sort Array By Parity II
https://leetcode.com/problems/sort-array-by-parity-ii/

Check SortArrayByParityII.cpp for brief solution explanation.
*/
class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int N = nums.length;
        LinkedList<Integer>evens = new LinkedList<Integer>();
        LinkedList<Integer>odds = new LinkedList<Integer>();
        for(int i = 0;i<N;i++){
            if(nums[i]%2==0){
                evens.add(nums[i]);
            }else{
                odds.add(nums[i]);
            }
        }
        int[]ans = new int[N];
        int p1 = 0, p2 = 0;
        for(int i = 0;i<N;i++){
            if(i%2==0){
                ans[i] = evens.get(p1++);
            }else{
                ans[i] = odds.get(p2++);
            }
        }
        return ans;
    }
}