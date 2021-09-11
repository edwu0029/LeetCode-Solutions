/*
LeetCode Medium: 1980. Find Unique Binary String
https://leetcode.com/problems/find-unique-binary-string/

Brief Solution Explanation:
N = Length of nums
- Since N is relatively small(Only going up to a maximum of 16), we can loop through all
2^N numbers and for each, check if it appears in nums. If not, we have an answer.
- An answer always exists since 2^N>N for all 1<=N<=16
- When looping through the 2^N numbers, be sure to add leading zeros to make the number has N digits

Time Complexity: O(2^N*N)
Memory Complexity: O(N)
*/
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int N = nums.size();
        string ans = "";
        for(int mask = 0;mask<(1<<N);mask++){
            string cur = "";
            for(int i = 0;i<N;i++){
                if(mask&(1<<i)){
                    cur = "1"+cur;
                }else{
                    cur = "0"+cur;
                }
            }
            bool check = true;
            for(int i = 0;i<N;i++){
                if(cur==nums[i]){
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
};