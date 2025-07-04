#define ll long long
class Solution {
public:

    vector<vector<ll>>adj;
    vector<ll>cost;

    vector<ll>check(ll node, ll parent,vector<ll>&answer) {
        vector<ll>ans = {cost[node]};
        ll subtreeSize = 1;
        for(auto it : adj[node]) {
            if(it == parent) continue;
            subtreeSize++;
            vector<ll>child = check(it,node,answer);
            for(auto it1 : child) ans.push_back(it1);
        }

        sort(ans.rbegin(),ans.rend());
        ll sz = ans.size();

        if(ans.size() < 3) { answer[node] = 1; return ans; }
        else {
            if(ans[1] * ans[2] > ans[sz-1] * ans[sz-2]) {
                answer[node] = ans[0] * ans[1] * ans[2];
            }
            else {
                answer[node] = ans[0] * ans[sz-1] * ans[sz-2];
            }
        }
        if(answer[node] < 0) answer[node] = 0;

        if(ans.size() <= 5) return ans;
        return {ans[0],ans[1],ans[2],ans[sz-1],ans[sz-2]};
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& c) {
        ll n = edges.size() + 1;
        adj = vector<vector<ll>>(n);
        for(auto it : edges) {
            ll u = it[0]; ll v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<ll>ans(n,0);
        for(int i = 0;i < c.size();i++) cost.push_back(c[i] * 1LL);
        check(0,-1,ans);
        // cout << " hi "<< endl;
        return ans;
    }
};
