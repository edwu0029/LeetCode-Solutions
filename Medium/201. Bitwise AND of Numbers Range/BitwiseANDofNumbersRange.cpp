/*
LeetCode Medium: 201. Bitwise AND of Numbers Range
https://leetcode.com/problems/bitwise-and-of-numbers-range/

Brief Solution Explanation:
- To better understand the solution to this problem, let's list out some examples

Ex 1(left = 9, right = 12)
Binary representations:
12:  1100 <--- right
11:  1011
10:  1010
09:  1001
08:  1000 <--- left
---------
ans: 1000 = 8

Ex 2(left = 217, right = 223)
223: 11011111 <--- right
222: 11011110
221: 11011101
220: 11011100
219: 11011011
218: 11011010
217: 11011001 <--- left
-------------
ans: 11011000 = 216
- Let us focus on just the binary representations of left and right
- You will notice that if we look at the bits from LEFT-SIDE TO RIGHT-SIDE, if that bit is the same
in left and right, it will be included in the answer
- However as soon as we reach a bit that is different between left and right, the rest of the bits
in the answer become zeros
- This allows us to do a simple algorithm where we compare compare the bits of left and right, starting
from the left-side
    - If the bits between left and right are equal, add it to answer
    - Otherwise, break

Time Complexity: O(log(max(left, right)))
Memory Complexity: O(1)
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i = 31;i>=0;i--){
            int l = ((1<<i)&left)>0, r = ((1<<i)&right)>0;
            if(l==r){
                ans+=l*(1<<i);
            }else{
                break;
            }
        }
        return ans;
    }
};

