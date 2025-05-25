class Solution {
public:

    vector<vector<int>>adj;
    int n;
    int target = 1;
    int mod = 1e9 + 7;
    vector<vector<int>>dp;
    
    void targetNode() {
        queue<pair<int,pair<int,int>>>q; // node,depth
        q.push({-1,{1,0}});
        int maxi = 0;
        while(!q.empty()) {
            int par = q.front().first;
            int node = q.front().second.first;
            int depth = q.front().second.second;
            q.pop();
            if(depth > maxi) {
                target = node; maxi = depth;
            }
            for(auto it : adj[node]) {
                if(it == par) continue;
                q.push({node,{it,depth + 1}});
            }
        }
    }

    int check(int node,int sum,int parent) {
        if(node == target) {
            if(sum & 1) return 1;
            return INT_MIN;
        }

        if(dp[node][sum] != -1) return dp[node][sum];

        int total = 0;
        for(auto it : adj[node]) {
            if(it == parent) continue;
            int temp1 = check(it,(sum + 1) % 2,node);
            int temp2 = check(it,(sum + 2) % 2,node);

            if(temp1 != INT_MIN) total = (total + temp1) % mod;
            if(temp2 != INT_MIN) total = (total + temp2) % mod;
        }
        return dp[node][sum] = total % mod;
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) {
        n = edges.size()+1;
        adj = vector<vector<int>>(n + 1);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        targetNode();
        dp = vector<vector<int>>(n+1,vector<int>(2,-1));
        int ans = check(1,0,-1) % mod;
        // cout << ans << endl;
        return ans % mod;
    }
};
