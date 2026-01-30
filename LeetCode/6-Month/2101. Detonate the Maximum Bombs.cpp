class Solution {
public:
    typedef long long ll;

    int bfs(int start, vector<vector<int>>& adj, int n) {
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;
        int count = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : adj[curr]) {
                if (!visited[next]) {
                    visited[next] = true;
                    count++;
                    q.push(next);
                }
            }
        }
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();
        vector<vector<int>> adj(n);

        // Build directed graph
        for (int i = 0; i < n; i++) {
            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];

                ll dist = (x2 - x1) * (x2 - x1) +
                          (y2 - y1) * (y2 - y1);

                if (dist <= r1 * r1) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, bfs(i, adj, n));
        }

        return ans;
    }
};
