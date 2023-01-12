/*
LeetCode Medium: 1443. Minimum Time to Collect All Apples in a Tree
https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

Brief Solution Explanation:
N = Number of nodes in the tree
M = Number of edges
- We know that this graph is a tree, allowing us to use the concept of subtrees to help us solve this problem
- Let subtreeHasApples[i] represent if:
    - There is an apple at node i
    - There is an apple in the subtree of node i
- It can be seen then that we MUST visit all node i that have subtreeHasApples[i] to capture all the apples
- We can perform one dfs to solve for all subtreeHasApples[i] and solve the time required as well
- Let sum[i] represent the time required to collect all the apples in the subtree of i, including node i itself
- Performing a bottom up dfs approach that starts as node 0, for every node u:
    - If there is an apple at node u, then subtreeHasApples[u] = true
    - Let v be any child of node u
    - If any of subtreeHasApples[v]==true, then subtreeHasApples[u] as there apples in the subtree of u
        - This would indicate that we must visit node v
        - sum[u]+=2+sum[v] for all v such that subtreeHasApples[v]==true
            - The 2 seconds comes from one second to go down from u to v, and another second to eventually come
            back up from v top u
            - sum[v] must be added since we also need to pick up apples that may be in v's subtree
- sum[0] is our final answer

Time Complexity: O(N+M)
Memory Complexity: O(N)
*/
class Solution {
    vector<vector<int>>adj;
    vector<bool>subtreeHasApples;
    vector<bool>vis;
    vector<int>sum;
public:
    int minTime(int N, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(N);
        vis.resize(N);
        sum.resize(N);
        subtreeHasApples.resize(N);
        // Create adjacency list of edges
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, hasApple);
        return sum[0];
    }
    bool dfs(int u, vector<bool>& hasApple){
        vis[u] = true;
        if(hasApple[u]){
            subtreeHasApples[u] = true;
        }
        for(int nxt:adj[u]){
            if(!vis[nxt]){
                bool t = dfs(nxt, hasApple);
                if(t){
                    sum[u]+=2+sum[nxt];
                }
                subtreeHasApples[u] = subtreeHasApples[u]||t;
            }
        }
        return subtreeHasApples[u];
    }
};