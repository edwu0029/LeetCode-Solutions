/*
LeetCode Medium: 49. Group Anagrams
https://leetcode.com/problems/group-anagrams/description/

Brief Solution Explanation:
N = Length of strs
M = Maximum Length of strs[i] for 0<=i<N
- We can generate a frequency array, freq, for each string, str[i] to figure out the anagram groups
    - freq[j] = Number of times character j appears in the string str[i]
    - Any word that is a anagram of str[i] will have the SAME frequency array
- We can use a map to keep track of anagram groups with string(freq) as key and vector of strings for value
    - For the key, we can compress freq to a string
    - For the value, keep track of all str[k] where str[k] has the same frequency as the key
- We can finally loop through all values of the map and put them into a vector ans

- Note that the java and python solutions use the lexicographically sorted version of the string as the 
indicator for anagram. It servers the same purpose as the frequency array:
    - str[a] and str[b] are anagrams if they are the same when sorted lexicographically

Time Complexity: O(N*M)
Memory Complexity: O(N*M)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int N = strs.size();
        unordered_map<string, vector<string>>m;
        //Calculate frequencies
        for(int i = 0;i<N;i++){
            int M = strs[i].size();
            vector<int>freq(26);
            for(int j = 0;j<M;j++){
                freq[strs[i][j]-'a']++;
            }
            //Compress frequency array to string
            string cur = "";
            for(int j = 0;j<26;j++){
                cur+=freq[j];
            }
            m[cur].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto [s, g]: m){
            ans.push_back(g);
        }
        return ans;
    }
};