/*
LeetCode Medium: 17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Check LetterCombinationsOfAPhoneNumber.cpp for brief solution explanation.
*/
class Solution {
    HashMap<Character, String>comb;
    public List<String> letterCombinations(String digits) {
        comb = new HashMap<Character, String>();
        comb.put('2', "abc");
        comb.put('3', "def");
        comb.put('4', "ghi");
        comb.put('5', "jkl");
        comb.put('6', "mno");
        comb.put('7', "pqrs");
        comb.put('8', "tuv");
        comb.put('9', "wxyz");
        List<String>ans = new LinkedList<String>();
        String cur = "";
        rec(digits, 0, cur, ans);
        return ans;
    }
    public void rec(String digits, int idx, String cur, List<String>ans){
        if(idx==digits.length()){
            if(!cur.equals("")){
                ans.add(cur);
            }
            return;
        }
        String letters = comb.get(digits.charAt(idx));
        for(int i = 0;i<letters.length();i++){
            cur+=letters.charAt(i);
            rec(digits, idx+1, cur, ans);
            cur = cur.substring(0, cur.length()-1);
        }
    }
}