/*
LeetCode Medium: 151. Reverse Words in a String
https://leetcode.com/problems/reverse-words-in-a-string/

Brief Solution Explanation:
N = Length of s
- We can use a simple two-pointer approach to find the left and right indices of each word, then use a substring function
to add that word to the final reversed string
- Let us start with the left and right most pointers at N-1
- For each word, let us do the following:
    - Move the left and right most pointers as far to the left, until they reach a non-space character
    - If left or right pointers move out of bounds, then break as we are done processing string s completely
    - Otherwise, move the left pointer as far to the left of the current word. This can be found by finding the greatest l such that
    s[l-1] is a space and l>0
    - We can then add s[l:r], the current word, to our reversed string
    - Finally, make left and right pointers equal l-1, and repeat for the next word
- Note that we may need to trim the final string to remove trailing and leading spaces

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    string reverseWords(string s) {
        int N = s.size(), l = N-1, r = N-1;
        string ans = "";
        while(true){
            while(r>=0&&s[r]==' '){
                l--;
                r--;
            }
            if(l<0||r<0){
                break;
            }
            while(l>=1&&s[l-1]!=' '){
                l--;
            }
            ans+=s.substr(l, r-l+1)+" ";
            r = l = l-1;
        }
        if(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
    }
};