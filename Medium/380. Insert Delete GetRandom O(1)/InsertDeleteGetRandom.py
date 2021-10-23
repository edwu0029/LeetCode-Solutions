'''
LeetCode Medium: 380. Insert Delete GetRandom O(1)
https://leetcode.com/problems/insert-delete-getrandom-o1/

Check InsertDeleteGetRandom.cpp for brief solution explanation.
'''
class RandomizedSet:
    
    def __init__(self):
        self.m = {}
        self.nums = []
        
    def insert(self, val: int) -> bool:
        if val in self.m:
            return False
        self.m[val] = len(self.nums)
        self.nums.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.m:
            return False
        idx_val, idx_last = self.m[val], len(self.nums)-1
        last = self.nums[idx_last]
        self.nums[idx_val], self.nums[idx_last] = last, val
        self.m[last] = idx_val
        self.nums.pop(idx_last)
        self.m.pop(val, None)
        return True

    def getRandom(self) -> int:
        return self.nums[floor(random.random()*len(self.nums))]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()