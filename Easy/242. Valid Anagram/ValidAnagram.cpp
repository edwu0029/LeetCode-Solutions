/*
LeetCode Easy: 242. Valid Anagram
https://leetcode.com/problems/valid-anagram/description/

Brief Solution Explanation:
Ns = Length of string s
Nt = Length of string t
- We can maintain a frequency array of all the characters in string s and t
- Frstly, s and t can ONLY be anagrams if they have the same length, if not, return false immediately
- Otherwise, loop through both s and t, to calcualte the frequency array freqs and freqt respectively
    - freqs[i] = The number of the character i in string s
    - freqt[i] = The number of the character i in string t
- Loop through all 26 characters in freqs and freqt
    - If freqs[i]!=freqt[i] for any i in 0<=i<26, then they are NOT anagrams
- Return true otherwise

Time Complexity: O(Ns)
Memory Complexity: O(Ns)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int Ns = s.size();
        int Nt = t.size();
        //Check lengths
        if(Ns!=Nt){
            return false;
        }
        vector<int>freqs(26), freqt(26);
        //Calculte frequency arrays
        for(int i = 0;i<Ns;i++){
            freqs[s[i]-'a']++;
            freqt[t[i]-'a']++;
        }
        //Compare frequency arrays
        for(int i = 0;i<26;i++){
            if(freqs[i]!=freqt[i]){
                return false;
            }
        }
        return true;
    }
};