/*
LeetCode Easy: 1137. N-th Tribonacci Number
https://leetcode.com/problems/n-th-tribonacci-number/

Brief Solution Explanation:
N = The inputted number
- Considering the constraints for this particular version of the question are very small, a simple
simulation of the adding process can be done
- We can create an array where tribonacci[i] = the ith tribonacci number
- Fill in the base cases(tribonacci[0], tribonacci[1], and tribonacci[2]) loop to calculate each
tribonacci[i] where tribonacci[i] = tribonacci[i-1]+tribonacci[i-2]+tribonacci[i-3]
- Our final answer is tribonacci[N]

Time Complexity: O(N)
- Memory can be optimized to O(1) by just keeping track of the last 3 tribonacci numbers
- For clarity, the code below will be O(N) memory
Memory Complexity: O(N)
*/
class Solution {
public:
    int tribonacci(int n) {
        vector<int>tribonacci(max(3, n+1));
        tribonacci[0] = 0;
        tribonacci[1] = 1;
        tribonacci[2] = 1;
        for(int i = 3;i<=n;i++){
            tribonacci[i] = tribonacci[i-1]+tribonacci[i-2]+tribonacci[i-3];
        }
        return tribonacci[n];
    }
};
/*
Alternate/Extended Solution(Matrix Exponentiation):
- The above simulation runs in linear time and will be too slow for larger values of N
- We can instead, represent the tribonacci sequence using linear algebra and matricies
    - We can use a matrix and use matrix multiplication and binary exponentiation to
    solve this in log time
    - Very similar to how we can represent the fibonacci sequence as a matrix. For more info:
    https://medium.com/@andrew.chamberlain/the-linear-algebra-view-of-the-fibonacci-sequence-4e81f78935a3
- We can use the following matrix representation for the Nth tribonacci number
|1 1 0|     |tribonacci[N-1]|
|1 0 0|^N x |tribonacci[N-2]|
|0 1 0|     |tribonacci[N-3]|

      |tribonacci[N-1]+tribonacci[N-2]+tribonacci[N-3]|   |tribonacci[N]  |
    = |tribonacci[N-1]                                | = |tribonacci[N-1]|
      |tribonacci[N-2]                                |   |tribonacci[N-2]|

- To do the matrix multiplication to power N, we can use binary exponentiation to this in log time
- Of course, if N is too large, the tribonacci numbers will be too large to fit in a 32 or 64 bit
number; using a mod(1e9+7) may be required
M = Length of matrix side(3 in this case)

Time Complexity: O(M^2*logN)
Memory Complexity: O(M^2)
*/
class Solution {
public:
    vector<vector<int>>mult(vector<vector<int>>m1, vector<vector<int>>m2){
        int A = m1.size(), B = m2[0].size(), M = m1[0].size();
        //Resulting matrix will be AxB in size
        //M is length of common side between m1 and m2
        vector<vector<int>>res(A, vector<int>(B, 0));
        for(int i = 0;i<A;i++){
            for(int j = 0;j<B;j++){
                for(int t = 0;t<M;t++){
                    res[i][j]+=m1[i][t]*m2[t][j];
                }
            }
        }
        return res;
    }
    vector<vector<int>>bin_pow(vector<vector<int>>base, int exp){
        if(exp==1){
            return base;
        }
        vector<vector<int>>t = bin_pow(base, exp/2);
        t = mult(t, t);
        if(exp%2==0){
            return t;
        }
        return mult(base, t);
    }
    int tribonacci(int n) {
        vector<vector<int>>m = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
        vector<vector<int>>intial = {{1}, {1}, {0}};
        if(n<=2){
            return intial[2-n][0];
        }
        vector<vector<int>>ans = mult(bin_pow(m, n-2), intial);
        return ans[0][0];
    }
};
