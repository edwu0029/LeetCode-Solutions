/*
LeetCode Medium: 978. Longest Turbulent Subarray
https://leetcode.com/problems/longest-turbulent-subarray/

Brief Solution Explanation:
N = Lengthh of arr
- We can use a simple greedy solution to solve this problem in linear time
- Loop through all index i where 1<=i<N:
    - inc = Longest valid subarray length ending in i that ends with a increasing difference(arr[i-1]<arr[i])
    - dec = Longest valid subarray length ending in i that ends with a decreasing difference(arr[i-1]>arr[i])
    - For each arr[i-1] and arr[i] pair, we can update inc and dec depending on the current difference
    - If arr[i-1]>arr[i], inc = dec+1 (Append current difference to dec) and restart dec, dec = 1
    - If arr[i-1]<arr[i], dec = inc+1 (Append current difference to inc) and restart inc, inc = 1
    - If arr[i-1]==arr[i], we need to restart both, inc = dec = 1

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int N = arr.size(), ans = 1, inc = 1, dec = 1;
        for(int i = 1;i<N;i++){
            if(arr[i-1]==arr[i]){
                //If two adjacent elements are equal, restart inc and dec
                inc = dec = 1;
            }else if(arr[i-1]>arr[i]){
                dec = inc+1;
                inc = 1;
            }else{
                inc = dec+1;
                dec = 1;
            }
            ans = max(ans, max(inc, dec));
        }
        return ans;
    }
};