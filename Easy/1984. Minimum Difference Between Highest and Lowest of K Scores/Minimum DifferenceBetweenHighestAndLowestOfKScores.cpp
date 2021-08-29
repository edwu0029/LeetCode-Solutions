/*
LeetCode Easy: 1984. Minimum Difference Between Highest and Lowest of K Scores
https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

Brief Solution Explanation:
N = Length of nums array
- First, N==1 is a special case in which we can just return 0. For N>=2, we can generalize with the method below
- Given that we want to minimize the range of some k numbers, we first sort nums. From now on, nums will refer to the sorted array
- Since the array is sorted, we know that if we fix the lowest score to num[i], it is always optimal to choose num[i+k-1] as
the highest score. If we choose some num[j] as the highest where i+k-1<j, the difference will be larger since num[i+k-1]<num[j]
- In nums, for each possible subarray [i, i+k-1], we can find the range and update the answer accordingly
    - Range of [i, i+k-1]: nums[i+k-1]-nums[i]

Time Complexity: O(NlogN)
Memory Complexity: O(1)
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int N = nums.size();
        if(N==1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = nums[N-1];
        for(int i = 0;i+k-1<N;i++){
            ans = min(ans, nums[i+k-1]-nums[i]);
        }
        return ans;
    }
};