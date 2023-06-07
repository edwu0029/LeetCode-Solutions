/*
LeetCode Easy: 520. Detect Capital
https://leetcode.com/problems/next-greater-element-i/

Brief Solution Explanation:
N = Length of word
- This problem requires one simple loop through the word to count the number of capital letters
- We can then check the 3 valid cases individually to see if ANY are satisfied
- Case 1 (All capitals):
    - Simply check if the number of capitals is equal to N
- Case 2 (No capitals):
    - Simply check if the number of capitals is equal to 0
- Case 3 (Only first letter is capital):
    - Simply check if the number of capitals is equal to 1 AND the first letter is capital
- If none of the three cases are satisfied, then then usage of capitals is not right

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    bool detectCapitalUse(string word) {
        int N = word.size();
        int capitals = 0;
        for(int i = 0;i<word.size();i++){
            if(isCapital(word[i])){
                capitals++;
            }
        }
        if(capitals==0||capitals==N||(capitals==1&&isCapital(word[0]))){
            return true;
        }else{
            return false;
        }
    }
    bool isCapital(char a){
        return 'A'<=a&&a<='Z';
    }
};