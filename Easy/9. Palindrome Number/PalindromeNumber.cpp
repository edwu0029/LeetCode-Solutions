/*
LeetCode Easy: 9. Palindrome Number
https://leetcode.com/problems/palindrome-number/

Brief Solution Explanation:
N = Number of digits in x
- Convert the number to a string num
- Loop index i from 0 to N/2:
    - If num[i]!=num[N-i-1], the number is not a palindrome, return false
- Otherwise the number is a palindrome, return true

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int N = num.length();
        for(int i = 0;i<N/2;i++){
            if(num[i]!=num[N-i-1]){
                return false;
            }
        }
        return true;
    }
};