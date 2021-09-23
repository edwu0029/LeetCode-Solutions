/*
LeetCode Medium: 1239. Maximum Length of a Concatenated String with Unique Characters
https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

Brief Solution Explanation:
N = Length of arr
M = Sum of length of all strings in arr
- A simple bitmask approach will allow us to try all possible combination of strings
- Firstly, we can convert each string into a int for faster and easier comparing
    - Convert a string arr[i] into an int used[i] where if the ith bit is 1, represents if the (i+1)th letter of the alphabet
    exists in the string
    - Ex. "abd" -> 00000000000000000000001011
    - If the string has duplicate letters, we can just set its respective int to 0 and comapare these special cases
    separately
- Check all 2^N bitmasks where each bitmask repsents a certain combination of strings
    - If the ith bit in the bitmask is 1, the ith string is used in this combination
    - To compare, we can use the bitwise AND operator to check if any digits are duplicated across the
    strings as well as thee cases where if any of the string have duplicate letters(where used[i]==0)
    - If there are no conflicts, we can update our answer accordingly with the total length of strign lengths for this bitmask

Time Complexity: O(M+2^N*N)
Memory Complexity: O(N)
*/
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int N = arr.size();
        vector<int>used;
        for(int i = 0;i<N;i++){
            int cur = 0;
            for(int j = 0;j<arr[i].size();j++){
                if(cur&(1<<(arr[i][j]-'a'))){
                    cur = 0;
                    break;
                }else{
                    cur|=(1<<(arr[i][j]-'a'));
                }
            }
            used.push_back(cur);
        }
        int ans = 0;
        for(int mask = 0;mask<(1<<N);mask++){
            int cur = 0, len = 0;
            bool check = true;
            for(int i = 0;i<N;i++){
                if(mask&(1<<i)){
                    if(used[i]==0||cur&used[i]){
                        check = false;
                        break;
                    }else{
                        cur|=used[i];
                        len+=arr[i].size();
                    }
                }
            }
            if(check){
                ans = max(ans, len);
            }
        }
        return ans;
    }
};