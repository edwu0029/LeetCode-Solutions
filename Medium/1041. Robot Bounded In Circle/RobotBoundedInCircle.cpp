/*
LeetCode Medium: 1041. Robot Bounded In Circle
https://leetcode.com/problems/robot-bounded-in-circle/

Brief Solution Explanation:
N = Length of insutrctions
- Note that the robot starts facing north
- Let us do one round of instructions and say the ending point is (dx, dy)
- There are esentially two cases for the robot to be bounded by a circle
    1. The robot ends at the origin after one round of instrcutions, (dx, dy) = (0, 0)
    2. The robot doesn't end at the origin AND the robot is facing either WEST, SOUTH or NORTH
        - If the robot ends facing south, then it will always take 2 rounds of instructions to get back to the origin
        - If the robot ends facing west or east, then it will always take 4 rounds of instructions to get back to the origin
        - This can be proven by seeing that the delta changes (dx, dy) will always cancel after some number of rounds
- If the robot doesn't end at the origin and is facing NORTH, then the robot is NOT bounded by a circle
    - This is because it can be shown that the delta changes will never cancel
    - The robot will end up further and further from the origin after each round of instructions

Time Complexity: O(N)
Memory Complexity: O(1)
*/
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int N = instructions.size();
        //North, East, South, West
        vector<vector<int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        //Current location
        int x = 0, y = 0;
        //Current direction
        int d = 0;
        for(int i = 0;i<N;i++){
            if(instructions[i]=='L'){ //Rotate CCW
                d = (d+3)%4;
            }else if(instructions[i]=='R'){ //Rotate CW
                d = (d+1)%4;
            }else{
                x+=dir[d][0];
                y+=dir[d][1];
            }
        }
        return (x==0&&y==0)||d!=0;
    }
};