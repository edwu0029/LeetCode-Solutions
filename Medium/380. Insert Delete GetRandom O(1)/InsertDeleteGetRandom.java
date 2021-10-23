/*
LeetCode Medium: 380. Insert Delete GetRandom O(1)
https://leetcode.com/problems/insert-delete-getrandom-o1/

Check InsertDeleteGetRandom.cpp for brief solution explanation.
*/
class RandomizedSet {
    public HashMap<Integer, Integer>m;
    public ArrayList<Integer>nums;
    
    public RandomizedSet() {
        this.m = new HashMap<Integer, Integer>();
        this.nums = new ArrayList<Integer>();
    }
    
    public boolean insert(int val) {
        if(m.containsKey(val)){
            return false;
        }
        m.put(val, nums.size());
        nums.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if(!m.containsKey(val)){
            return false;
        }
        int last = nums.get(nums.size()-1);
        int idx_val = m.get(val), idx_last = nums.size()-1;
        nums.set(idx_val, last);
        nums.set(idx_last, val);
        m.put(last, idx_val);
        nums.remove(idx_last);
        m.remove(val);
        return true;
    }
    
    public int getRandom() {
        return nums.get((int)(Math.random()*nums.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */