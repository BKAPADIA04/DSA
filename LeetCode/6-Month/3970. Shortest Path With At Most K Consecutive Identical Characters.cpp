#define ll long long
class Solution {
public:

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i < (int)edges.size();i++) {
            int u = edges[i][0]; int v = edges[i][1]; int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>pq;
        priority_queue<array<ll,3>, vector<array<ll,3>>, greater<array<ll,3>>>pq;
        vector<vector<ll>>dp(n, vector<ll>(k+1, LLONG_MAX));
        // vector<ll>dp(n, LLONG_MAX);
        dp[0][1] = 0;
        // dist, k, node
        pq.push({0, 1, 0});
        while(!pq.empty()) {
            array<ll,3>topp = pq.top();
            ll d = topp[0];
            ll tempK = topp[1];
            ll node = topp[2];
            ll color = labels[node] - 'a';
            pq.pop();

            if(d > dp[node][tempK]) continue;

            for(auto it : adj[node]) {
                int v = it.first; int wt = it.second;
                // if(v == par) continue;
                int colorV = labels[v] - 'a';
                int newCnt = 1;
                if(color == colorV) {
                    newCnt = tempK + 1;
                }

                if(newCnt > k) continue;

                if(d + wt < dp[v][newCnt]) {
                    dp[v][newCnt] = d + wt;
                    pq.push({dp[v][newCnt], newCnt, v});
                }

                // print(pq);
                // cout << endl;
            }
        }

        ll ans = LLONG_MAX;
        for(ll c = 1;c <= k;c++) {
            ans = min(ans, dp[n-1][c]);
        }
        if(ans == LLONG_MAX) return -1;
        return ans;
    }
};
