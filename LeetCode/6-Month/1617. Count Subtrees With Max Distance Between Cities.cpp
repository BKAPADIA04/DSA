class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        // Build adjacency list for the tree
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n - 1, 0);

        // Iterate over all subsets of nodes
        for (int mask = 1; mask < (1 << n); mask++) {
            int k = __builtin_popcount(mask);
            if (k <= 1) continue; // diameter requires at least 2 nodes

            // Collect nodes in this subset
            vector<int> nodes;
            for (int i = 0; i < n; i++) 
                if (mask & (1 << i)) nodes.push_back(i);

            // --- Connectivity check ---
            vector<int> seen(n, 0);
            stack<int> st;
            st.push(nodes[0]);
            seen[nodes[0]] = 1;
            int cnt = 1;

            while (!st.empty()) {
                int u = st.top(); st.pop();
                for (int v : adj[u]) {
                    // Only traverse if v is in subset and not visited
                    if ((mask & (1 << v)) && !seen[v]) {
                        seen[v] = 1;
                        cnt++;
                        st.push(v);
                    }
                }
            }

            if (cnt != k) continue; // not connected

            // --- Diameter computation ---
            auto bfs = [&](int start) {
                vector<int> dist(n, -1);
                queue<int> q;
                dist[start] = 0;
                q.push(start);
                int far = start;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : adj[u]) {
                        if ((mask & (1 << v)) && dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                            if (dist[v] > dist[far]) far = v;
                        }
                    }
                }
                return make_pair(far, dist[far]);
            };

            // First BFS: find farthest node from any node
            auto [far1, _] = bfs(nodes[0]);
            // Second BFS: find diameter from farthest node
            auto [far2, diameter] = bfs(far1);

            ans[diameter - 1]++;
        }

        return ans;
    }
};
