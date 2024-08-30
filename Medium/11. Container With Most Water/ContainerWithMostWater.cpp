/*
LeetCode Medium: 11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/description/

Brief Solution Explanation:
N = Length of height
- This problem can be solved using a two pointer approach
- Let us start with a left pointer (l) at index 0 and a right pointer (r) at index N-1
  - We compare the area covered by the heights at l and r by using the formula:
  area = min(height[l], height[r])*(r-l)
  - We should check if this current area is the best currently
  - Next, we should then determine which of height[l] or height[r] is smaller, and move it to the "center"
    - If height[l] is smaller, we want to move l to the right, or l++
    - Otherwise, we want to move r to the left, or r-- 
  - Why does this work? By only moving the pointer with smaller height, we are choosing to explore new areas that can 
  POTENTIALLY have higher area
    - The area is limited by the smallest height (remember the min(height[l], height[r]) part of the area formula)
    - If we were to move the taller height pointer, it would be IMPOSSIBLE for us to find a larger area than the current
      - This is because we even if we find a taller height, we are still limited by the same "smaller" height as before,
      but with a smaller width, resulting in smaller area
    - Moving the smaller height pointer gives a chance to improve the area as it is possible for us to find a larger height
    to offset the smaller width and give us a better area. Since this case exists from this move, we should choose to do this

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int ans = 0, l = 0, r = N-1;
        while(l<=r){
            ans = max(ans, min(height[l], height[r])*(r-l));
            //Move left or right pointers
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};