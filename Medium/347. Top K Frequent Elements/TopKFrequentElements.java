/*
LeetCode Medium: 347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/description/

Check TopKFrequentElements.cpp for brief solution explanation.
*/
class pair{
    public int x, y;
    pair(int a, int b){
        x = a;
        y = b;
    }
}
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int N = nums.length;
        HashMap<Integer, Integer>m = new HashMap<Integer, Integer>();
        for(int i = 0;i<N;i++){
            m.put(nums[i], m.getOrDefault(nums[i], 0)+1);
        }
        ArrayList<pair>freq = new ArrayList<pair>();
        for(int x: m.keySet()){
            freq.add(new pair(x, (int)m.get(x)));
        }
        Collections.sort(freq, new Comparator<pair>(){
            public int compare(pair a, pair b){
                return a.y-b.y;
            }
        });
        int[]ans = new int[k];
        for(int i = 1;i<=k;i++){
            ans[i-1] = freq.get(freq.size()-i).x;
        }
        return ans;
    }
}