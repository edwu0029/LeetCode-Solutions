/*
LeetCode Easy: 350. Intersection of Two Arrays II
https://leetcode.com/problems/intersection-of-two-arrays-ii/

Brief Solution Explanation:
N = Length of nums1
M = Length of nums2
- We can use a HashMap to maintain the frequency of each value in nums1. After, we can do the same with nums2 in another
HashMap
- Compare the key value pairs in each HashMap with each other and take the minimum value for each possible key
    - Lets say we are processing a key x
    - If freq1[x] = Occurences of x in nums1 and freq2[x] = Occurences of x in nums2
    - Our answer will contain min(freq1[x], freq2[x]) occurences of x in it
    - We can use a for loop to add the min(freq1[x], freq2[x])'s to our answer list

Time Complexity: O(N+M)
Memory Complexity: O(N+M)
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>freq1, freq2;
        int N = nums1.size(), M = nums2.size();
        for(int i = 0;i<N;i++){
            freq1[nums1[i]]++;
        }
        for(int i = 0;i<M;i++){
            freq2[nums2[i]]++;
        }
        vector<int>ans;
        //Comparing HashMap values
        for(pair<int, int>i: freq1){
            //freq1[i.first] = i.second
            int qty = min(i.second, freq2[i.first]);
            for(int j = 0;j<qty;j++){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};