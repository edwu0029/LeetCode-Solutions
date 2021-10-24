/*
LeetCode Medium: 451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/

Check SortCharactersByFrequency.cpp for brief solution explanation.
*/
class Solution {
    public String frequencySort(String s) {
        int N = s.length();
        HashMap<Character, Integer>m = new HashMap<Character, Integer>();
        for(int i = 0;i<N;i++){
            m.put(s.charAt(i), m.getOrDefault(s.charAt(i), 0)+1);
        }
        ArrayList<Character>[]buckets = new ArrayList[N+1];
        for(char i:m.keySet()){
            int freq = m.get(i);
            if(buckets[freq]==null){
                buckets[freq] = new ArrayList<Character>();
            }
            buckets[m.get(i)].add(i);
        }
        StringBuilder ans = new StringBuilder();
        for(int i = N;i>=1;i--){
            if(buckets[i]==null){
                continue;
            }
            for(char j:buckets[i]){
                for(int k = 0;k<i;k++){
                    ans.append(j);
                }
            }
        }
        return ans.toString();
    }
}