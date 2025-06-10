class Solution {
public:

    vector<vector<int>>adj;
    vector<int>coins;
    vector<vector<int>>dp;

    int check(int node, int parent,int option, int k) {
        if(dp[node][option] != -1) return dp[node][option];
        int ans = 0;
        int value = coins[node] / (1 << option);

        int pick1 = value - k;
        int pick2 = floor(value/2.0);

        for(auto it : adj[node]) {
            if(it == parent) continue;
            int value = coins[node];
            pick1 += check(it,node,option,k);
            if(option < 13) pick2 += check(it,node,option + 1,k); // 10^4/2^14 =0
        }
        return dp[node][option] = max(pick1,pick2);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coin, int k) {
        adj = vector<vector<int>>(edges.size() + 1);
        for(auto it:edges) {
            int u = it[0]; int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        coins = coin;
        dp = vector<vector<int>>(edges.size() + 1,vector<int>(15,-1));
        return check(0,-1,0,k);
    }
};
