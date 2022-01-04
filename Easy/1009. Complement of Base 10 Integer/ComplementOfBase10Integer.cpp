/*
LeetCode Easy: 1189. Maximum Number of Balloons
https://leetcode.com/problems/maximum-number-of-balloons/

Brief Solution Explanation:
-  We can simply loop through the digits of the binary representation of N
    - If the digit is 0, then that same digit will be a 1 in the complement
    - If the digit is 1, then that same digit will be a 0 in the complement
- We also must make sure to loop exactly logN digits in the binary representation of N
to make sure we don't count any leading zeros
- There is one corner case, where N = 0. We can check this case in the beginning and return
the answer of 1 if so

Time Complexity: O(logN)
Memory Complexity: O(1)
*/
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int complement = 0;
        for(int i = 0;i<log2(n);i++){
            if(!((1<<i)&n)){
                complement+=(1<<i);
            }
        }
        return complement;
    }
};