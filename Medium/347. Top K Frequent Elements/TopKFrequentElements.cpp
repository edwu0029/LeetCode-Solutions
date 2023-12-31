/*
LeetCode Medium: 347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/description/

Brief Solution Explanation:
N = Length of Nums
- We can generate a frequency array of the unique values in nums using a map m
    - m[i] = Frequency of i in nums
    - Eg. if 2 shows up 3 times in nums, m[2] = 3
- Map m is composed of pair values {a, m[a]} for each unique value, let's call this pair of ints p_a
- We can add all possible p_a's in m to a array/vector called freq, and sort based on p_a's second value, the frequency
- We can then loop through the last K elements of freq, getting the K largest frequency pairs

Time Complexity: O(NlogN)
Memory Complexity: O(N)
*/
class Solution {
public:
    bool cmp(const pair<int, int>&a, const pair<int, int>&b){
        return a.second<b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int N = nums.size();
        //Generate frequency array
        unordered_map<int, int>m;
        for(int i = 0;i<N;i++){
            m[nums[i]]++;
        }
        //Move to array
        vector<pair<int, int>>freq;
        for(auto &[a, b] :m){
            freq.push_back({a, b});
        }
        //Sort based on frequency
        sort(freq.begin(), freq.end(), [](const pair<int, int>&a, const pair<int, int>&b) ->bool{
            return a.second<b.second;
        });
        vector<int>ans;
        for(int i = 1;i<=k;i++){
            ans.push_back(freq[freq.size()-i].first);
        }
        return ans;
    }
};