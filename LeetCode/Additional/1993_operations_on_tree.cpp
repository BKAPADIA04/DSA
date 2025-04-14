class LockingTree {
public:

    unordered_map<int,int>lockToUser;
    vector<vector<int>>adj;
    vector<int>par;

    LockingTree(vector<int>& parent) {
        par = parent;
        adj = vector<vector<int>>(parent.size());
        for(int i = 1;i < parent.size();i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        int NUM = num;
        if(lockToUser.find(num) != lockToUser.end()) return false;
        lockToUser[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(lockToUser.find(num) == lockToUser.end()) return false;
        if(lockToUser[num] != user) return false;
        lockToUser.erase(num);
        return true;
    }
    
    bool descendCheck(int num) {
        if(lockToUser.find(num) != lockToUser.end()) {
            return true;
        }
        bool ans = false;
        for(auto it : adj[num]) {
            if(it == par[num]) continue;
            ans = ans || descendCheck(it);
        }
        return ans;
    }

    void unlockDescend(int num) {
        for(auto it : adj[num]) {
            if(it == par[num]) continue;
            if(lockToUser.find(it) != lockToUser.end()) {
                lockToUser.erase(it);
            }
            unlockDescend(it);
        }
    }


    bool upgrade(int num, int user) {
        int NUM = num;
        while(par[num] != -1) {
            if(lockToUser.find(num) != lockToUser.end()) return false;
            num = par[num];
        }
        if(lockToUser.find(0) != lockToUser.end()) return false;
        if(!descendCheck(NUM)) return false;
        unlockDescend(NUM);
        lockToUser[NUM] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */1
