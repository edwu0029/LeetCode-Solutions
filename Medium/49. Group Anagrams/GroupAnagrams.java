/*
LeetCode Medium: 49. Group Anagrams
https://leetcode.com/problems/group-anagrams/description/

Check GroupAnagrams.cpp for brief solution explanation.
*/
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int N = strs.length;
        HashMap<String, List<String>>m = new HashMap<>();
        for(int i = 0;i<N;i++){
            char[]t = strs[i].toCharArray();
            Arrays.sort(t);
            String cur = new String(t);
            if(!m.containsKey(cur)){
                m.put(cur, new ArrayList<String>());
            }
            m.get(cur).add(strs[i]);
        }
        List<List<String>>ans = new ArrayList<List<String>>();
        for(List<String>cur: m.values()){
            ans.add(cur);
        }
        return ans;
    }
}