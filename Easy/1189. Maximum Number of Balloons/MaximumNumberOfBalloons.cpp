/*
LeetCode Easy: 1189. Maximum Number of Balloons
https://leetcode.com/problems/maximum-number-of-balloons/

Brief Solution Explanation:
N = Length of text
- Count the frequency of each letter in text
- Our answer is the minimum of all freq[letter_in_balloon]/# of times letter appears in balloon
    - Ex. freq['a'-'a']/1 since 'a' only appears once in "balloon"
    - Ex. freq['o'-'a']/2 since 'l' appears twice in "balloon"
    - And so on for all letters in "balloon"
    - The -'a' is just needed to map a to index 0, b to index 1, c to index 2, ...

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26);
        int N = text.size();
        for(int i = 0;i<N;i++){
            freq[text[i]-'a']++;
        }
        int ans = freq['b'-'a']; //For b
        ans = min(ans, freq[0]); //For a
        ans = min(ans, freq['l'-'a']/2); //For l
        ans = min(ans, freq['o'-'a']/2); //For o
        ans = min(ans, freq['n'-'a']); //For n
        return ans;
    }
};