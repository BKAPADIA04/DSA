class Solution {
public:

    int findParent(int u,vector<int>&parent) {
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u],parent);
    }

    void unionByRank(vector<int>&rank,vector<int>&parent,int u,int v,int wt) {
        int ult_u = findParent(u,parent);
        int ult_v = findParent(v,parent);
        if(ult_u == ult_v) {
            return;
        }
        if(rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u;
        }
        else if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        }
        else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int>answer(query.size(),-1);
        vector<int>rank(n+1,0); vector<int>parent(n+1,0);
        for(int i = 0;i < n;i++) parent[i] = i;
        vector<int>ands(n+1,-1);
        
        for(int i = 0;i < edges.size();i++) {
            int u = edges[i][0]; int v = edges[i][1]; int wt = edges[i][2];
            unionByRank(rank,parent,u,v,wt);
        }
        for(int i = 0;i < edges.size();i++) {
            int u = edges[i][0]; int v = edges[i][1]; int wt = edges[i][2];
            int ult_u = findParent(u,parent);
            int ult_v = findParent(v,parent);
            if(ult_u == ult_v) {
                ands[ult_u] = ands[ult_v] & wt;
            }
        }
        for(int i = 0;i < query.size();i++) {
            int u = query[i][0]; int v = query[i][1];
            int ult_u = findParent(u,parent);
            int ult_v = findParent(v,parent);
            if(ult_u != ult_v) {
                answer[i] = -1;
            }
            else {
                answer[i] = ands[ult_u];
            }
        }
        return answer;
    }
};
