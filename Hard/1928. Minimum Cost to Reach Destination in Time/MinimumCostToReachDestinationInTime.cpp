/*
LeetCode Hard: 1928. Minimum Cost to Reach Destination in Time
https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/

Brief Solution Explanation:
N = Number of cities
E = Total number of edges
- Since we know time always increases as you move and the dimensions are fairly small, we can use a 2D dp method to solve this problem.
- dp state: dp[i][j] = min cost to travel to city j in i time
- Initially, all dp[i][j] = inf
- Initial state: dp[0][0] = passingFees[0]
- Loop through all possible times i where 0<=i<=maxTime
    - If the dp state hasn't been reached yet(dp[i][j]==inf), simply continue
    - For each possible city, transition dp value to its neighbouring cities by using an adjacency list
    - Let u be the current city and e be the current edge being processed
    dp[e.time+t][e.v] = min(dp[e.time+t][e.v], dp[u][t]+passingFees[v])
 
- For each possible time i, we are looping all cities and edges connected to those cities. This is the equivalent of looping over all
edges twice, once from each end. Thus we are looping 2*E per time i
Time Complexity: O(maxTime*E)
Memory Complexity: O(maxTime*N)
*/
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int N = passingFees.size();
        vector<vector<pair<int, int>>>adj(N, vector<pair<int, int>>());
        //Convert edges array to adjacency list
        for(int i = 0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int t = edges[i][2];
            adj[a].push_back({b, t});
            adj[b].push_back({a, t});
        }
        vector<vector<int>>dp(maxTime+1, vector<int>(N, 0x3f3f3f3f));
        dp[0][0] = passingFees[0];
        for(int i = 0;i<maxTime;i++){
            for(int j = 0;j<N;j++){
                if(dp[i][j]>=0x3f3f3f3f){
                    continue;
                }
                for(pair<int, int>e:adj[j]){
                    int v = e.first, newTime = i+e.second;
                    if(newTime<=maxTime){
                        dp[newTime][v] = min(dp[newTime][v], dp[i][j]+passingFees[v]);
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0;i<=maxTime;i++){
            ans = min(ans, dp[i][N-1]);
        }
        return (ans>=0x3f3f3f3f)?-1:ans;
    }
};