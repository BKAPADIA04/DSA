class Solution {
public:

    void print(vector<int>answer) { for(auto it:answer) cout << it << " "; cout << endl;}

    void dfs_bob(vector<vector<int>>&adj,vector<int>&depth,vector<int>&parent,int dep,int node, int par) {
        depth[node] = dep;
        parent[node] = par;

        for(auto it:adj[node]) {
            if(it == par) continue;
            dfs_bob(adj,depth,parent,dep+1,it,node);
        }
    }


    int dfs_alice(vector<vector<int>>&adj,int node,int par,vector<int>&amount) {
        int answer = amount[node]; int maxi = INT_MIN;
        for(auto it:adj[node]) {
            if(it == par) continue;
            maxi = max(maxi,dfs_alice(adj,it,node,amount));
        }
        return maxi == INT_MIN ? answer : answer + maxi;
    }
    

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>>adj(n);
        for(auto it:edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>depth(n,0); vector<int>parent(n,-1);
        dfs_bob(adj,depth,parent,0,0,-1);

        int curr = bob; int dep = 0;
        while(curr != -1) {
            if(depth[curr] > dep) amount[curr] = 0;
            else if(depth[curr] == dep) amount[curr] /= 2;

            curr = parent[curr];
            dep++;
        }
        print(amount);

        return dfs_alice(adj,0,-1,amount);
    }
};
