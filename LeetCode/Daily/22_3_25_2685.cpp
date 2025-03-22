class Solution {
public:

    int findParent(vector<int>&parent,int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent,parent[x]);
    }

    void unionBySize(vector<int>&parent,vector<int>&size,int x,int y) {
        int ult_x = findParent(parent,x);
        int ult_y = findParent(parent,y);
        if(ult_x == ult_y) return;

        if(size[ult_x] > size[ult_y]) {
            parent[ult_y] = ult_x;
            size[ult_x] += size[ult_y];
        }
        else {
            parent[ult_x] = ult_y;
            size[ult_y] += size[ult_x];
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>parent(n+1,0); vector<int>size(n+1,1);
        for(int i = 0;i < parent.size();i++) {
            parent[i] = i;
        }
        for(int i = 0;i < edges.size();i++) {
            int u = edges[i][0]; int v = edges[i][1];
            unionBySize(parent,size,u,v);
        }
        vector<int>edgesParent(n+1,0);
        for(int i = 0;i < edges.size();i++) {
            int u = edges[i][0]; int v = edges[i][1];
            if(findParent(parent,u) == findParent(parent,v)) {
                int ult_par = findParent(parent,u);
                edgesParent[ult_par]++;
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++) {
            if(parent[i] == i) {
                int s = size[parent[i]];
                int req = (s * (s-1)) / 2;
                if(req == edgesParent[parent[i]]) ans++;
            }
        }
        return ans;
    }
};
