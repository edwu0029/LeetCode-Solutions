/*
LeetCode Medium: 1041. Robot Bounded In Circle
https://leetcode.com/problems/robot-bounded-in-circle/

Check RobotBoundedInCircle.cpp for brief solution explanation.
*/
class Solution {
    public boolean isRobotBounded(String instructions) {
        int N = instructions.length();
        int[][]dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0;
        int d = 0;
        for(int i = 0;i<N;i++){
            if(instructions.charAt(i)=='L'){
                d = (d+3)%4;
            }else if(instructions.charAt(i)=='R'){
                d = (d+1)%4;
            }else{
                x+=dir[d][0];
                y+=dir[d][1];
            }
        }
        return (x==0&&y==0)||d!=0;
    }
}