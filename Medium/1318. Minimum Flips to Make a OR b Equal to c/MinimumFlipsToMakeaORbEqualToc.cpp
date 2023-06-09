/*
LeetCode Medium: 1318. Minimum Flips to Make a OR b Equal to c
https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

Brief Solution Explanation:
- We want to flip bits in A and B such that A|B = C
- Since the ith bit in C ONLY depends on the ith bit of A and ith bit of C, we simply need deal with each ith bit
"column" case by case
- Additionally, we are given that 1<=A, B, C <=10^9, so we will only need to deal with at most 30 bits, thus runtime won't
be an issue for potentially TLE
- Let count be the total number of flips needed
- We must loop through i from 0 to log2(maximum of A, B, and C)
    - Let a_i be the ith bit in A
    - Let b_i be the ith bit in B
    - Let c_i be the ith bit in C
    - Notice that if c_i is 0:
        - a_i AND b_i must be both 0
    - Notice that if c_i is 1:
        - ONE OR BOTH of a_i or b_i is needed due to the OR operation

    - Therefore, for each c_i, we can calcualte the flips needed by using two cases
        - Case 1: c_i is 0
            - If a_i is 1, count++ since it needs to be flipped to 0
            - If b_i is 1, count++ since it also needs to be flipped to 0
        - Case 2: c_i is 1
            - If BOTH a_i and b_i are 0, count++ since we only need to flip one of them to get c_i = 1
            - Otherwise do nothing
- We can then return count at the very end for our final answer

Time Complexity: O(log(max(A, B, C)))
Memory Complexity: O(1)
*/
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 0;(1<<i)<=max(a, max(b, c));i++){
            int a_i = a&(1<<i);
            int b_i = b&(1<<i);
            int c_i = c&(1<<i);
            if(c_i==0){
                //a_i AND b_i must be 0
                count+=(a_i>0)+(b_i>0);
            }else{
                //one of either a_i and b_i needs to be 1
                if(a_i+b_i==0){
                    count++;
                }
            }
        }
        return count;
    }
};