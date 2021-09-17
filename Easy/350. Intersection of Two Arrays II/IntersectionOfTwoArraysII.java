/*
LeetCode Easy: 350. Intersection of Two Arrays II
https://leetcode.com/problems/intersection-of-two-arrays-ii/

Check IntersectionOfTwoArraysII.cpp for brief solution explanation.
*/
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int N = nums1.length, M = nums2.length;
        HashMap<Integer, Integer>freq1 = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer>freq2 = new HashMap<Integer, Integer>();
        for(int i = 0;i<N;i++){
            if(freq1.containsKey(nums1[i])){
                freq1.replace(nums1[i], freq1.get(nums1[i])+1);
            }else{
                freq1.put(nums1[i], 1);
            }
        }
        for(int i = 0;i<M;i++){
            if(freq2.containsKey(nums2[i])){
                freq2.replace(nums2[i], freq2.get(nums2[i])+1);
            }else{
                freq2.put(nums2[i], 1);
            }
        }
        List<Integer>ans_list = new LinkedList<Integer>();
        for(int i:freq1.keySet()){
            int t1 = (freq1.get(i)==null)? 0: freq1.get(i);
            int t2 = (freq2.get(i)==null)? 0: freq2.get(i);
            int qty = Math.min(t1, t2);
            for(int j = 0;j<qty;j++){
                ans_list.add(i);
            }
        }
        int[]ans = new int[ans_list.size()];
        for(int i = 0;i<ans_list.size();i++){
            ans[i] = ans_list.get(i);
        }
        return ans;
    }
}