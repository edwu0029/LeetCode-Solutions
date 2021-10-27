/*
LeetCode Easy: 155. Min Stack
https://leetcode.com/problems/min-stack/

Brief Solution Explanation:
- To simulate a Min Stack, we can use a dynamic array(vector in c++, arraylist in java, list in python, etc)
to keep track of the values in the stack as well as the minimum value of the stack when each value is inserted
    - Essentially, we can keep track of two stacks, one for the order of values and the other for the minimum
    values after each element was added
- top() is simply the element at the top of the value stack
- getMin() is simply the element at the top of the minimum value stack
- Whenever we want to push() a new element val, we can add val to the value stack and add min(val, getMin()) to
the minimum value stack
- To pop(), we just pop() from BOTH the value stack and the minimum value stack

Value stack:      Minimum value stack:
| -5 |               | -5 |  <-- new minimum element
| 1  |               | -2 |
| -2 |               | -2 |  <-- new minimum element
| 10 |               | 5  |
| 5  |               | 5  |  <-- New minimum element
| 20 |               | 20 |
*/
class MinStack {
public:
    vector<pair<int, int>>stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.size()<=0){
            stk.push_back(make_pair(val, val));
        }else{
            stk.push_back(make_pair(val, min(val, getMin())));
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk[stk.size()-1].first;
    }
    
    int getMin() {
        return stk[stk.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */