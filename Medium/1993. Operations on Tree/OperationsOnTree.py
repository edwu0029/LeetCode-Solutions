'''
LeetCode Medium: 1993. Operations on Tree
https://leetcode.com/problems/operations-on-tree/

Check OperationsOnTree.cpp for brief solution explanation.
'''
class LockingTree:

    def __init__(self, parent: List[int]):
        N = len(parent)
        self.parents = []
        self.adj = [[] for i in range(N)]
        self.locked = [False for i in range(N)]
        self.locked_user = [0 for i in range(N)]
        for i in range(N):
            self.parents.append(parent[i])
            if i!=0:
                self.adj[i].append(parent[i])
                self.adj[parent[i]].append(i)

    def lock(self, num: int, user: int) -> bool:
        if not self.locked[num]:
            self.locked[num] = True
            self.locked_user[num] = user
            return True
        else:
            return False

    def unlock(self, num: int, user: int) -> bool:
        if self.locked[num] and self.locked_user[num]==user:
            self.locked[num] = False
            self.locked_user[num] = -1
            return True
        else:
            return False

    def check_lock(self, u) -> bool:
        if self.locked[u]:
            return True
        for v in self.adj[u]:
            if v==self.parents[u]:
                continue
            if self.check_lock(v):
                return True
        return False

    def check_ancestors(self, u) -> bool:
        if u==-1:
            return True
        if self.locked[u]:
            return False
        return self.check_ancestors(self.parents[u])

    def unlock_des(self, st, u):
        if u!=st:
            self.locked[u] = False
        for v in self.adj[u]:
            if v==self.parents[u]:
                continue
            self.unlock_des(st, v)

    def upgrade(self, num: int, user: int) -> bool:
        if self.locked[num] or not self.check_lock(num) or not self.check_ancestors(num):
            return False
        self.unlock_des(num, num)
        self.locked[num] = True
        self.locked_user[num] = user
        return True


# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)