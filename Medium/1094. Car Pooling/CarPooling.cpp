/*
LeetCode Medium: 1094. Car Pooling
https://leetcode.com/problems/car-pooling/

Brief Solution Explanation:
N = Length of trips array
D = Maximum possible distance in trips
- Since the maximum distance we can possibly travel is relatively small, we can keep track of the maximum number of people we need to
carry for each day
- This can be calculated by summing the number of people required each day by all the trips. For example, 

trips = [[2,1,5],[3,3,7]]
Trip 1:     . 2 2 2 2 . .
Trip 2:     . . . 3 3 3 3
--------------------------
Sum:        0 2 2 5 5 3 3

- We can do this quickly by using a difference array approach
https://codeforces.com/blog/entry/78762
    - Essentialy, to add q to all elements in the range [L, R], we do:
        1. sum[L]+=q (Add to value to start of the interval)
        2. sum[R+1]-=q (Once interval is over, substract the value)
    - Then if we want to find the value at some position i, we use cumulative sum/prefix sum up to i
        - value[i] = sum[1]+sum[2]+ ... +sum[i]
- Using the approach above, we can add the number of passengers needed for each trip in their respective interval
- We can then loop through each possible day, find the value for that day using prefix sum up to i, and check if it exceeds the capacity
    - If so, then we return false
- Otherwise, we return true

Time Complexity: O(N+D)
Memory Complexity: O(D)
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int N = trips.size(), D = 0;
        for(int i = 0;i<N;i++){
            D = max(D, trips[i][2]+1);
        }
        vector<int>sum(D+1);
        //Set up difference array
        for(int i = 0;i<N;i++){
            sum[trips[i][1]]+=trips[i][0];
            sum[trips[i][2]]-=trips[i][0];
        }
        for(int i = 0;i<=D;i++){
            if(i>0){ //Accumulate sum up to position i
                sum[i]+=sum[i-1];
            }
            if(sum[i]>capacity){
                return false;
            }
        }
        return true;
    }
};