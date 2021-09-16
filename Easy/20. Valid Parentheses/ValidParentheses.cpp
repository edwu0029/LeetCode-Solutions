/*
LeetCode Easy: 20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/

Brief Solution Explanation:
N = Length of string s
- We can use a simple intuitive method
- Loop through each character from left to right
    - If the character is a left bracket, we can push it into a stack/stack-like data structure such as a list.
    This helps us keep track of the order in which brackets need to be closed
    - If the character is a right bracket, we need to make sure it is the same type of bracket as the top of the stack
    since brackets need to be closed in the right order
    - If they are the same type, we can pop from the stack and continue on processing, otherwise, we know that the brackets were closed
    in the wrong order and we can just return false
- Finally, we need to check if they stack is empty(All left brackets were closed with right brackets), if so, we return true

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    bool isValid(string s) {
        int N = s.size();
        map<char, int>m;
        m['{'] = m['}'] = 1;
        m['('] = m[')'] = 2;
        m['['] = m[']'] = 3;
        vector<int>stk;
        for(int i = 0;i<N;i++){
            int cur = m[s[i]];
            if(s[i]=='{'||s[i]=='('||s[i]=='['){
                stk.push_back(cur);
            }else{
                if(stk.size()<=0||stk[stk.size()-1]!=cur){
                    return false;
                }else{
                    stk.pop_back();
                }
            }
        }
        return stk.size()==0;
    }
};