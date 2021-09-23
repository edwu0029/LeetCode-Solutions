/*
LeetCode Medium: 1239. Maximum Length of a Concatenated String with Unique Characters
https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

Check MaximumLengthOfAConcatenatedStringWithUniqueCharacters.cpp for brief solution explanation.
*/
class Solution {
    public int maxLength(List<String> arr) {
        int N = arr.size();
        int[]used = new int[N];
        for(int i = 0;i<N;i++){
            for(int j = 0;j<arr.get(i).length();j++){
                if((used[i]&(1<<(arr.get(i).charAt(j)-'a')))>0){
                    used[i] = 0;
                    break;
                }else{
                    used[i]|=(1<<(arr.get(i).charAt(j)-'a'));
                }
            }
        }
        int ans = 0;
        for(int mask = 0;mask<(1<<N);mask++){
            int cur = 0, len = 0;
            boolean check = true;
            for(int i = 0;i<N;i++){
                if((mask&(1<<i))>0){
                    if(used[i]==0||(cur&used[i])>0){
                        check = false;
                        break;
                    }else{
                        cur|=used[i];
                        len+=arr.get(i).length();
                    }
                }
            }
            if(check){
                ans = Math.max(ans, len);
            }
        }
        return ans;
    }
}