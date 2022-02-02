/*
LeetCode Medium: 1993. Operations on Tree
https://leetcode.com/problems/operations-on-tree/

Check OperationsOnTree.cpp for brief solution explanation.
*/
class LockingTree {
    int[]parents;
    boolean[]locked;
    int[]locked_user;
    ArrayList<Integer>[]adj;
    public LockingTree(int[] parent) {
        int N = parent.length;
        parents = new int[N];
        locked = new boolean[N];
        locked_user = new int[N];
        adj = new ArrayList[N];
        for(int i = 0;i<N;i++){
            adj[i] = new ArrayList<Integer>();
        }
        for(int i = 0;i<N;i++){
            parents[i] = parent[i];
            if(i!=0){
                adj[i].add(parent[i]);
                adj[parent[i]].add(i);
            }
        }
    }
    
    public boolean lock(int num, int user) {
        if(!locked[num]){
            locked[num] = true;
            locked_user[num] = user;
            return true;
        }else{
            return false;
        }
    }
    
    public boolean unlock(int num, int user) {
        if(locked[num]&&locked_user[num]==user){
            locked[num] = false;
            locked_user[num] = -1;
            return true;
        }else{
            return false;
        }
    }
    
    public boolean check_lock(int u){ //For upgrade function
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
    
    public boolean check_ancestors(int u){ //For upgrade function
        if(u==-1){
            return true;
        }
        if(locked[u]){
            return false;
        }
        return check_ancestors(parents[u]);
    }
    
    public void unlock_des(int st, int u){ //For upgrade function
        if(u!=st){
            locked[u] = false;
        }
        for(int v:adj[u]){
            if(v==parents[u]) continue;
            unlock_des(st, v);
        }
    }
    
    public boolean upgrade(int num, int user) {
        if(locked[num]){
            return false;
        }
        if(!check_lock(num)){
            return false;
        }
        if(!check_ancestors(num)){
            return false;
        }
        unlock_des(num, num);
        locked[num] = true;
        locked_user[num] = user;
        return true;
    }
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree obj = new LockingTree(parent);
 * boolean param_1 = obj.lock(num,user);
 * boolean param_2 = obj.unlock(num,user);
 * boolean param_3 = obj.upgrade(num,user);
 */