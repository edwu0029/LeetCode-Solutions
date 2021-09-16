/*
LeetCode Easy: 20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/

Check ValidParentheses.cpp for brief solution explanation.
*/
class Solution {
    public boolean isValid(String s) {
        int N = s.length();
        HashMap<Character, Integer>m = new HashMap<Character, Integer>();
        m.put('{', 1); m.put('}', 1);
        m.put('(', 2); m.put(')', 2);
        m.put('[', 3); m.put(']', 3);
        Stack<Integer>open = new Stack<Integer>();
        for(int i = 0;i<N;i++){
            int cur = m.get(s.charAt(i));
            if(s.charAt(i)=='{'||s.charAt(i)=='('||s.charAt(i)=='['){
                open.add(cur);
            }else{
                if(open.size()<=0||open.peek()!=cur){
                    return false;
                }else{
                    open.pop();
                }
            }
        }
        return open.size()==0;
    }
}