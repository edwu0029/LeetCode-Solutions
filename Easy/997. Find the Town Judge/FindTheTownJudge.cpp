/*
LeetCode Easy: 997. Find the Town Judge
https://leetcode.com/problems/find-the-town-judge/

Brief Solution Explanation:
N = Number of people
T = Length of trust array
- We can imagine this problem as a directed graph where the people are nodes and all pairs in the trust array are edges
    - Every [A, B] describes a directed edge from person A to person B
- We can keep track of the indegree and outdegree for each person/node
    - Indegree is the number of edges pointing into a node
    - in[i] = indegree of person i
    - Outdegree is the number of edges pointing out of a node
    - out[i] = outdegree of person i
    - Looping through the trust array, we can update the indegree and outdegree values
        - For each edge [A, B]
        - Add one outdegree to out[A]
        - Add one indegree to in[B]
- If there exists a person i such that out[i]==0 and in[i]==n-1, then person i is the judge
- Otherwise, there is no judge, return -1

Time Complexity: O(N+T)
Memory Complexity: O(N)
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>out(n+1), in(n+1);
        int T = trust.size();
        for(int i = 0;i<T;i++){
            int a = trust[i][0], b = trust[i][1];
            out[a]++;
            in[b]++;
        }
        for(int i = 1;i<=n;i++){
            if(out[i]==0&&in[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};