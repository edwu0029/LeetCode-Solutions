/*
LeetCode Medium: 1328. Break a Palindrome
https://leetcode.com/problems/break-a-palindrome/

Brief Solution Explanation:
- A simple greedy algorithm and simple case work to do this
- Case 1(Impossible to break palindrome)
    - The only case where we won't be able to break a palindrome is if it has length 1
    - We can handle this special case separately
- Case 2(All a's)
    - Since we won't the lexicographically smallest answer, if we have all a's we can simply change the
    last character to a b
- Case 3(All other strings)
    - We can greedily pick the left-most non-'a' character and change it to a 'a'
    - This breaks the palindrome and gives us the lexicographically smallest answer

Time Complexity: O(N)
- Strings are mutable in C++ so memory complexity is O(1)
- However strings aren't mutable in Java and Python, so we have to create another string for the
answer. Thus memory complexity is O(N) in those languages
Memory Complexity: O(1)
*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int N = palindrome.size();
        if(N==1){
            return "";
        }
        bool done = false;
        for(int i = 0;i<N/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i] = 'a';
                done = true;
                break;
            }
        }
        if(!done){
            palindrome[N-1] = 'b';
        }
        return palindrome;
    }
};