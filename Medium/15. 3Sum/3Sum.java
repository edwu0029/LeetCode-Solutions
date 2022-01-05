/*
LeetCode Medium: 15. 3Sum
https://leetcode.com/problems/3sum/

Check 3Sum.cpp for brief solution explanation.
*/
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int N = nums.length;
        Arrays.sort(nums);
        List<List<Integer>>ans = new LinkedList<>();
        for(int l = 0;l<N-2;l++){
            int m = l+1, r = N-1;
            while(m<r&&m<N&&r<N){
                int sum = nums[m]+nums[r];
                if(sum<-nums[l]){
                    m++;
                }else if(sum>-nums[l]){
                    r--;
                }else{
                    List<Integer>t = new LinkedList<Integer>();
                    t.add(nums[l]);
                    t.add(nums[m]);
                    t.add(nums[r]);
                    ans.add(t);
                    int mid = nums[m], right = nums[r];
                    while(m<r&&nums[m]==mid){
                        m++;
                    }
                    while(m<r&&nums[r]==right){
                        r--;
                    }
                }
            }
            while(l+1<N-2&&nums[l]==nums[l+1]){
                l++;
            }
        }
        return ans;
    }
}