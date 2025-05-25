class Solution {
public:
    #define ll long long
    #define M 1000000007
    ll power(ll x, ll n) {
        ll res = 1;
        while (n) {
            if (n & 1) {
                res = ((res) * (x))%M;
            }
            x = ((x) * (x))%M;
            n = n >> 1;
        }
        return res%M;
    }
    void dfs(int cur, int par, vector<int>& depth, vector<int> &dist,vector<vector<int>>& dp,
             vector<vector<int>>& adj) {
        depth[cur] = 1 + (par == -1 ? 0 : depth[par]);
        if (par != -1)
            dp[cur][0] = par;
        for (int j = 1; j < 21; j++) {
            dp[cur][j] = dp[dp[cur][j - 1]][j - 1];
        }
        for (auto& it : adj[cur]) {
            if (it != par) {
                 dist[it]=dist[cur] + 1;
                dfs(it, cur, depth, dist, dp, adj);
            }
        }
    }
    int find_lca(int x, int y, vector<int>& depth, vector<vector<int>>& dp) {
        int da = depth[x], db = depth[y];
        if (da > db) {
            swap(x, y);
        }
        int diff = abs(db - da);
        for (int i = 0; i < 21 && diff; i++) {
            if (diff & (1 << i)) {
                y = dp[y][i];
            }
        }
        if (x == y)
            return x;

        for (int i = 20; i >= 0; i--) {
            if (dp[x][i] != dp[y][i]) {
                x = dp[x][i];
                y = dp[y][i];
            }
        }
        return dp[x][0];
    }
    int find_distance(int x, int y, vector<int>& depth, vector<int>& dist,
                      vector<vector<int>>& dp) {
        int lca = find_lca(x, y, depth, dp);
        return dist[x] + dist[y] - 2 * dist[lca];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& e,
                                  vector<vector<int>>& q) {
        int n =e.size()+1;
        vector<vector<int>> adj(n + 1);
        for (auto& edge : e) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> depth(n + 1, 0),dist(n+1,0);
        vector<vector<int>> dp(n + 1, vector<int>(21, 0));
        dfs(1, -1, depth, dist, dp, adj); // cur,par,

        vector<int> ans;
        for (int i = 0; i < q.size(); i++) {
            if(q[i][0]==q[i][1]){
                ans.push_back(0);
            }else{
                int d = find_distance(q[i][0],q[i][1],depth,dist,dp);
            ans.push_back(power(2,d-1));
            }
            
        }
        return ans;
    }
};
