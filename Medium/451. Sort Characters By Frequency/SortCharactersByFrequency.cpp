/*
LeetCode Medium: 451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/

Brief Solution Explanation:
N = Length of string s
- We can loop through the string s and keep track of the frequency of each type of character that appears
- Since each possible frequency value will be in the range [0, 1, 2, ... N-1, N], we can use a bucket sort to 
prevent any kind of built in sorting which would add a log factor to the time complexity
- Let buckets[i] = A sequence of characters where each character has frequency of i
    - Ex. If 'a' has a frequency of 2, buckets[2] = "a"
    - Ex. If 'a' and 'B' has a frequency of 4, buckets[4] = "aB"
- Loop through all buckets[i] from greatest i to lowest where 0<=i<=N, and add all buckets[i] sequences to a final
string, duplicating each character i times in the final string
    - NOTE: normal string concatenation is linear in time complexity.
    - To prevent this, we can use push_back on strings in C++ or use StringBuilder in Java

Time Complexity: O(N)
Memory Complexity: O(N)
*/
class Solution {
public:
    string frequencySort(string s) {
        int N = s.size();
        unordered_map<char, int>m;
        for(auto i:s){
            m[i]++;
        }
        vector<vector<char>>buckets(N+1);
        //Structure binding in c++17
        for(auto [c, freq]:m){
            buckets[freq].push_back(c);
        }
        string ans = "";
        for(int i = N;i>=1;i--){
            if(!buckets[i].size()){
                continue;
            }
            for(auto j:buckets[i]){
                for(int k = 0;k<i;k++){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};