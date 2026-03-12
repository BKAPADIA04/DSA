class DSU {
    public:
    int n;
    vector<int>parent;
    vector<int>size;
    int comps;

    DSU(int n_) {
        n = n_;
        comps = n;
        size = vector<int>(n,1);
        parent = vector<int>(n,0);
        for(int i = 0;i < parent.size();i++) parent[i] = i;
    }

    int findParent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    bool unionBySize(int a, int b) {
        int ultX = findParent(a);
        int ultY = findParent(b);

        if(ultX == ultY) return false;
        if(size[a] < size[b]) {
            size[b] += size[a];
            parent[ultY] = ultX;
        }
        else {
            size[a] += size[b];
            parent[ultX] = ultY;
        }
        comps--;
        return true;
    }
};

class Solution {
public:

    bool check(vector<vector<int>>&edges, int n, int k, int mid) {
        DSU dsu(n);
        int upgrades = 0;
        for(auto it : edges) {
            int must = it[3];
            if(must == 1) {
                if(it[2] < mid) return false;
                if(!dsu.unionBySize(it[0],it[1])) return false;
            }
        }

        vector<pair<int,int>>normal,upgrade;
        for(auto it : edges) {
            int u = it[0]; int v = it[1]; int str = it[2]; int must = it[3];
            if(must == 1) continue;
            if(str >= mid) {
                normal.push_back({u,v});
            }
            else if(str * 2 >= mid) {
                upgrade.push_back({u,v});
            }
        }

        for(auto it : normal) {
            dsu.unionBySize(it.first,it.second);
        }

        for(auto it : upgrade) {
            if(dsu.findParent(it.first) != dsu.findParent(it.second)) {
                if(upgrades == k) break;
                dsu.unionBySize(it.first,it.second);
                upgrades++;
            }
        }

        return dsu.comps == 1;
    }
    
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int maxi = 0;
        for(auto it : edges) {
            maxi = max(maxi, 2 * it[2]);
        }

        if(!check(edges,n,k,0)) return -1;
        int low = 1; int high = maxi;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(edges,n,k,mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
