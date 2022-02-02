/*
LeetCode Medium: 1993. Operations on Tree
https://leetcode.com/problems/operations-on-tree/

Brief Solution Explanation:
- Firstly, let us use the parent array given in the constructor to produce a adjacency list for the tree
    - This willmake it easier to traverse the tree in the future
- We should also keep two arrays in the LockingTree class:
    - Let the locked array represent if nodes are locked or not
        - locked[i] = true if node i is locked
        - locked[i] = false if node i is not locked
    - Let locked_user represent the user who locked a certain node
        - locked_user[i] = if node i is locked, the user who locked node i
- Lock:
    - Simply look at the locked array and update accourdingly
- Unlock:
    - Simply look at the locked_user array and if it matches with the current node, then update accourdingly
- Upgrade:
    - To upgrade, we need to satisfy the 3 conditions
    - Checking if the node is locked or not is trivial and can be done using the Lock function we already implemented
    - Checking for at least one locked descendant can be done by traveresing the tree and checking for any locked descendents
    - Chekcing for any locked ascenstors can be done by traversing the parent array upwards to the root
    - If all three conditions are met, we can simply traverse all the children and unlock them
*/
class LockingTree {
    vector<int>parents;
    vector<bool>locked;
    vector<int>locked_user;
    vector<vector<int>>adj;
public:
    LockingTree(vector<int>& parent) {
        int N = parent.size();
        adj.resize(N);
        for(int i = 0;i<N;i++){
            parents.push_back(parent[i]);
            if(i>0){
                adj[i].push_back(parent[i]);
                adj[parent[i]].push_back(i);
            }
        }
        locked.resize(N);
        locked_user.resize(N);
    }
    
    bool lock(int num, int user) {
        if(!locked[num]){
            locked[num] = true;
            locked_user[num] = user;
            return true;
        }else{
            return false;
        }
    }
    
    bool unlock(int num, int user) {
        if(locked[num]&&locked_user[num]==user){
            locked[num] = false;
            locked_user[num] = -1;
            return true;
        }else{
            return false;
        }
    }
    
    bool check_lock(int u){ //For upgrade function
        if(locked[u]){
            return true;
        }
        for(int v:adj[u]){
            if(v==parents[u]) continue;
            if(check_lock(v)){
                return true;
            }
        }
        return false;
    }
    
    bool check_ancestors(int u){ //For upgrade function
        if(u==-1){ //Reached root without returning false, thus no locked ancestors
            return true;
        }
        if(locked[u]){
            return false;
        }
        return check_ancestors(parents[u]);
    }
    
    void unlock_des(int st, int u){ //For upgrade function
        if(u!=st){
            locked[u] = false;
        }
        for(int v:adj[u]){
            if(v==parents[u]) continue;
            unlock_des(st, v);
        }
    }
    
    bool upgrade(int num, int user) {
        //1. The node is unlocked
        if(locked[num]){
            return false;
        }
        //2. It has at least one locked descendant (by any user)
        if(!check_lock(num)){
            return false;
        }
        //3. It does not have any locked ancestors
        if(!check_ancestors(num)){
            return false;
        }
        //Unlock all descendants
        unlock_des(num, num);
        //Lock current node
        locked[num] = true;
        locked_user[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */