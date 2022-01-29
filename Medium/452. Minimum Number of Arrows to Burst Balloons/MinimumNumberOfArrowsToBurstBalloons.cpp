/*
LeetCode Medium: 452. Minimum Number of Arrows to Burst Balloons
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

Brief Solution Explanation:
N = Length of points
- We can use a simple greedy approach to solve this problem
- It is always optimal to shoot an arrow at x such that x is the right bound of some balloon
- Therefore, we can first sort all the balloons by their right bound
- We can loop through the sorted balloons, for all balloons[i]
    - If we need another arrow to pop the current balloon[i], add to the counter and skip pall other ballons that this arrow will pop
        - This arrow will pop all balloons j such that balloon[j]'s left<=balloon[i]'s right

Time Complexity: O(NlogN)
Memory Complexity: O(1)
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int N = points.size();
        if(N==0){
            return 0;
        }
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b) -> bool{
            return a[1]<b[1];
        });
        //Current balloon
        vector<int>cur = points[0];
        int ans = 1;
        for(int i = 1;i<N;i++){
            if(cur[1]<points[i][0]){ //Need to use another arrow
                ans++;
                cur = points[i];
            }
        }
        return ans;
    }
};