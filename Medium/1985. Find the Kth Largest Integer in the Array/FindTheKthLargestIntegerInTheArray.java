/*
LeetCode Medium: 1985. Find the Kth Largest Integer in the Array
https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

Check FindTheKthLargestIntegerInTheArray.cpp for brief solution explanation.
*/
class Solution {
    public String kthLargestNumber(String[] nums, int k) {
        int N = nums.length;
        Arrays.sort(nums, new Comparator<String>(){
            public int compare(String a, String b){
                if(a.length()==b.length()){
                    return a.compareTo(b);
                }else{
                    return a.length()-b.length();
                }
            }
        });
        return nums[N-k];
    }
}