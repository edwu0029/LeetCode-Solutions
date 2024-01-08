/*
LeetCode Medium: 3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Brief Solution Explanation:
N = Length of string s
- We can use a sliding window approach to solve this problem
- Let us start with l = 0 and r = 0, these "pointers" will define our sliding window
    - Let us find the LARGEST window such that s[l:r-1] has no repeating characters (With l fixed, moving r)
    - We can maintain a "frequency" map/array to keep track of which characters are in the current window
        - If freq[s[i]]!=0, then the character s[i] exists in the current window s[l:r-1]
    - Keep moving r to the right as long as:
        1. r is in range for s, in other words r<N
        2. freq[s[r]]!=0, in other words s[r] is NOT currently in the current window

        - We will also have to update freq as we move r, freq[s[r]]++
    - Now that we have the current window, we can check if this is the best answer
        - Length of current window of unique characters = r-l
        - ans = max(ans, r-l)
    - Now that we know the best answer with l fixed, we can move l once to the right and repeat
        - Note that if s[l:r-1] is made of unique characters, so will s[l+1:r-1]
        - When we move l to the right, we also must update freq, freq[s[l]]--;
- We can do one last check for ans and return ans

Time Complexity: O(N)
- Time complexity is O(N) since the pointers l and r each traverse the length of the string s, O(2N) = O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size();
        if(N==0) return 0;
        int l = 0, r = 0, ans = 0;
        map<char, int>freq;
        while(l<N){
            while(r<N&&freq[s[r]]==0){
                freq[s[r]]++;
                r++;               
            }
            ans = max(ans, r-l);
            //Move l
            freq[s[l]]--;
            l++;
        }
        ans = max(ans, r-l);
        return ans;
    }
};