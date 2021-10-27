/*
LeetCode Easy: 155. Min Stack
https://leetcode.com/problems/min-stack/

Check MinStack.cpp for brief solution explanation.
*/
class MinStack {
    public ArrayList<Integer>min_stk;
    public ArrayList<Integer>stk;
    public MinStack() {
        min_stk = new ArrayList<Integer>();
        stk = new ArrayList<Integer>();
    }
    
    public void push(int val) {
        if(stk.size()<=0){
            stk.add(val);
            min_stk.add(val);
        }else{
            stk.add(val);
            min_stk.add(Math.min(getMin(), val));
        }
    }
    
    public void pop() {
        stk.remove(stk.size()-1);
        min_stk.remove(min_stk.size()-1);
    }
    
    public int top() {
        return stk.get(stk.size()-1);
    }
    
    public int getMin() {
        return min_stk.get(min_stk.size()-1);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */