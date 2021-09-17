/*
LeetCode Easy: 1979. Find Greatest Common Divisor of Array
https://leetcode.com/problems/find-greatest-common-divisor-of-array/

Brief Solution Explanation:
- Finding the maximum and minimum numbers can easily be done by looping through the array and updating accordingly
- To find gcd, we can use Euclidean algorithm to find the gcd of the max and min numbers.
    - Euclidean algorithm runs in log(min(a, b))
    - In C++, this is implemented in the stl function __gcd
    - More info about the Euclidean algorithm here: https://en.wikipedia.org/wiki/Euclidean_algorithm

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    /*
    Euclidean algorithm:
    int gcd(int a, int b){
        if(b==0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }
    */
    int findGCD(vector<int>& nums) {
        int max_num = -1, min_num = 1005;
        for(int i = 0;i<nums.size();i++){
            max_num = max(max_num, nums[i]);
            min_num = min(min_num, nums[i]);
        }
        return __gcd(max_num, min_num);
    }
};