/*
LeetCode Medium: 17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Brief Solution Explanation:
N = Length of digits
- A simple recursion technique can be used to generate all letter combinations
- We can use a map to map each number to a string of its possible letters
- For each iteration of the recursion, rec(digits, idx, cur, ans):
    - If idx==digits.size(), all digits have been processed and we can add the current letter combination in cur
      to ans and return
    - Otherwise, we must get the possible letters for the current digit
        - For each possible letter for the current digit, add it to cur, then call rec(digits, idx+1, cur, ans)
          then remove it from cur
- In the end, we can return ans as the final answer
- Since each digit can have up to 4 possible letters, we have a upper bound of 4^N possible letter combinations

Time Complexity: O(4^N)
Memory Complexity: O(4^N)
*/
class Solution {
public:
    unordered_map<char, string> comb =  {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string cur = "";
        rec(digits, 0, cur, ans);
        return ans;
    }
    void rec(string digits, int idx, string& cur, vector<string>&ans){
        if(idx==digits.size()){
            if(cur!=""){
                ans.push_back(cur);
            }
            return;
        }
        for(auto x: comb[digits[idx]]){
            cur+=x;
            rec(digits, idx+1, cur, ans);
            cur = cur.substr(0, cur.size()-1);
        }
    }
};