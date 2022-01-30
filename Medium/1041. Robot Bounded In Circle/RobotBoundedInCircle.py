'''
LeetCode Medium: 1041. Robot Bounded In Circle
https://leetcode.com/problems/robot-bounded-in-circle/

Check RobotBoundedInCircle.cpp for brief solution explanation.
'''
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        N = len(instructions)
        dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        x, y = 0, 0
        d = 0
        for i in range(N):
            if instructions[i]=='L':
                d = (d+3)%4
            elif instructions[i]=='R':
                d = (d+1)%4
            else:
                x+=dir[d][0]
                y+=dir[d][1]
        return (x==0 and y==0) or d!=0;