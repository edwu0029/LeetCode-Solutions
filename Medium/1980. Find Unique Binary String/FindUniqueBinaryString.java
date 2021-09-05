/*
LeetCode Medium: 1980. Find Unique Binary String
https://leetcode.com/problems/find-unique-binary-string/

Check FindUniqueBinaryString.cpp for brief solution explanation.
*/
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int N = nums.length;
        String ans = "";
        for(int mask = 0;mask<(1<<N);mask++){
            String cur = "";
            for(int i = 0;i<N;i++){
                if((mask&(1<<i))>0){
                    cur = "1"+cur;
                }else{
                    cur = "0"+cur;
                }
            }
            boolean check = true;
            for(int i = 0;i<N;i++){
                if(cur.equals(nums[i])){
                    check = false;
                    break;
                }
            }
            if(check){
                ans = cur;
                break;
            }
        }
        return ans;
    }
}