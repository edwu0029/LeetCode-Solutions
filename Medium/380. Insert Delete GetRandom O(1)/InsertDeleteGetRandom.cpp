/*
LeetCode Medium: 380. Insert Delete GetRandom O(1)
https://leetcode.com/problems/insert-delete-getrandom-o1/

Brief Solution Explanation:
- We can use a hash map and some sort of dynamic array to implement this randomized set
- We can use the hash map to store the indexs of the values in the randomized set and
use the dynamic array to store the values
- For insert:
    - We can use the hash map to check if the value exists in our randomized set or not
    in O(1) amortized. We return false if it already is
    - If not, we can simply add it to our dynamic array and add the value to the hash map;
    all in O(1) amortized
- For remove:
    - The remove function is more tricky as typically, removing an element from any dynamic array is
    O(N) as you will need to shift elements around when you remove an element
    - However, if you remove the last element of a dynamic array, it will take O(1) time
    - From this, we can first check if the value exists in our randomized set and return false if not
    - If it is, we can "move" our desired value to the back of the dynamic array, then pop it from the back
    in O(1)
        - Let nums be our dynamic array
        - Let val be the value to be removed and last be the value of the last element
        - Effectively, we are swapping the positions of val and last in nums
        - We must also update the values of m accordingly
            - m[val] = idx of last
            - m[last] = idx of val
        - Now, we can just pop out val from the back of nums and remove the val key
        from our hash map m
        - Done in O(1)
- For getRandom:
    - We can use a built in random number generator to generate a random number
    between 0 and nums.size()-1, call this idx
    - Simply return nums[idx]

Time Complexity per operation: O(1) amortized
*/
class RandomizedSet {
private:
    vector<int>nums;
    unordered_map<int, int>m;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()){
            return false;
        }
        nums.push_back(val);
        m[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()){
            return false;
        }
        int last = nums[nums.size()-1];
        int idx_val = m[val], idx_last = nums.size()-1;
        //Move the element to be removed to the back of the vector
        //Allows for O(1) pop from the back of the vector
        swap(nums[idx_last], nums[idx_val]);
        m[last] = idx_val;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        //random number between 0 and nums.size()-1
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */