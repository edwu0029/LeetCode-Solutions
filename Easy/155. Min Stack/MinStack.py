'''
LeetCode Easy: 155. Min Stack
https://leetcode.com/problems/min-stack/

Check MinStack.cpp for brief solution explanation.
'''
class MinStack:
    def __init__(self):
        self.stk = []
    
    def push(self, val: int) -> None:
        if len(self.stk)<=0:
            self.stk.append((val, val))
        else:
            self.stk.append((val, min(self.getMin(), val)))

    def pop(self) -> None:
        self.stk.pop(len(self.stk)-1)

    def top(self) -> int:
        return self.stk[-1][0]

    def getMin(self) -> int:
        return self.stk[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()