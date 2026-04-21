class DSU {
    public:
    vector<int>parent;

    DSU(int n) {
        parent = vector<int>(n,0);
        for(int i = 0;i < n;i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if(parent[x] == x) return parent[x];

        return parent[x] = findParent(parent[x]);
    }

    void unite(int x, int y) {
        int ultX = findParent(x);
        int ultY = findParent(y);

        if(ultX == ultY) return;

        parent[ultX] = ultY;
    }
};

class Solution {
public:

    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU *dsu = new DSU(n);

        for(auto it : allowedSwaps) {
            int x = it[0]; int y = it[1];
            dsu->unite(x,y);
        }

        unordered_map<int,unordered_map<int,int>>mp;
        int ans = 0;
        for(int i = 0;i < n;i++) {
            mp[dsu->findParent(i)][source[i]]++;
        }

        for(int i = 0;i < n;i++) {
            if(mp[dsu->findParent(i)][target[i]] > 0) {
                mp[dsu->findParent(i)][target[i]]--;
            }
            else ans++;
        }
        
        return ans;
    }
};
