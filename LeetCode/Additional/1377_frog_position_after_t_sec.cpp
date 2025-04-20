class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int,vector<int>>adj;
        for(int i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if(n == 1) return target == 1;

        vector<int>visited(n + 1,0);

        int level = 0;
        queue<pair<int,double>>q;
        q.push({1,1.0});
        visited[1] = 1;

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0;i < sz;i++) {
                int node = q.front().first;
                double prob = q.front().second;
                q.pop();
                int check = adj[node].size();
                if(node != 1) check -= 1;
                if(node == target) {
                    if(check == 0 && level <= t) return prob;
                    else if(check >= 1 && level < t) return 0.0;
                    else if(level == t) return prob;
                }
                if(check == 0) continue;
                for(auto it : adj[node]) {
                    if(visited[it]) continue;
                    visited[it] = 1;
                    double temp = 1.0 / (double)(adj[node].size() - 1);
                    if(node == 1) temp = 1.0 / (double)(adj[node].size());
                    q.push({it, prob * temp});
                }
            }
            level++;
        }
        return 0.0;
    }
};

/*class Solution {
public:
    double ans = 0.0;
    void dfs(int node, double prob, vector<int>& vis, vector<vector<int>>& adj,
             int target, int t) {
        vis[node] = 1;
        if (t == 0 || adj[node].empty()) {
            if (node == target) {
                ans = prob;
            }
            return;
        }
        int count = 0;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                count++;
            }
        }
        if (count == 0) {
            if (node == target) {
                ans = prob;
            }
            return;
        }
        for (auto k : adj[node]) {
            if (!vis[k]) {
                dfs(k, prob / count, vis, adj, target, t - 1);
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n + 1, 0);
        dfs(1, 1.0, vis, adj, target, t);
        return ans;
    }
};*/
