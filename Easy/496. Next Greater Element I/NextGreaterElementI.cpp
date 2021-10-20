/*
LeetCode Easy: 496. Next Greater Element I
https://leetcode.com/problems/next-greater-element-i/

Brief Solution Explanation:
N = Length of nums2
M = Length of nums1
- This problem can be solved in linear time using a monotonic stack
- We can precompute the "next greater element" for each element in nums2
- Loop through all indicies i in nums2
    - In our stack, let us maintain a non-increasing sub-sequence of the nums2[0], nums2[1], ... nums2[i-1]
    - With our current index, we then pop out all numbers in the stack that are smaller than nums2[i] as we now know
    their next greater element, our current number, nums2[i]
        - We can keep these answers in a hash map
    - After this, we will know that our stack is only left with elements larger than or equal to nums2[i]
    - We then must add nums2[i] to the stack
- Finally, we can find out the answer for each element in nums1 using the answers stored in the hash mao
    - If the element isn't contained in the hash map, the answer is -1 for that element

Time Complexity: O(N+M)
Memory Complexity: O(N+M)
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int N = nums2.size(), M = nums1.size();
        stack<int>stk;
        unordered_map<int, int>m;
        for(int i = 0;i<N;i++){
            //Pop out elements smaller than nums2[i], their answer is the current number, nums2[i]
            while(stk.size()&&stk.top()<nums2[i]){
                //Store answer in hash map
                m[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        vector<int>ans(M);
        for(int i = 0;i<M;i++){
            if(m.count(nums1[i])){
                ans[i] = m[nums1[i]];
            }else{
                ans[i] = -1;
            }
        }
        return ans;
    }
};