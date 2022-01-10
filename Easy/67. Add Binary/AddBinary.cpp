/*
LeetCode Easy: 67. Add Binary
https://leetcode.com/problems/add-binary/

Brief Solution Explanation:
N = Length of string a
M = Length of string b
- Since N and M can be up to 10^4 in length, it is far too large to simply store as a integer and compute normally
    - No primitive data type can store 2^(10^4) = 2^10000
- For this problem, we can simulate the adding process of binary numbers just like how we would add them by hand
- Here is a simple tutorial: https://web.math.princeton.edu/math_alive/1/Lab1/BinAdd.html
- Working column by column and right to left, we can add the two binary strings
    - Remember to keep track of any carry

Time Complexity: O(max(N, M))
Memory Complexity: O(max(N, M))
*/
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()){ //To generalize, make a the longer of the two strings
            swap(a, b);
        }
        //We need to work from right to left
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans = "";
        int carry = 0;
        for(int i = 0;i<a.size();i++){
            int cur = carry+(a[i]-'0');
            if(i<b.size()){
                cur+=(b[i]-'0');
            }
            //Calcualte carry for next digit column
            carry = cur/2;
            //Add digit to answer
            ans+=((cur%2)+'0');
        }
        if(carry>0){
            ans+=(carry+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};