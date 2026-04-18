#define ll long long
class Solution {
public:

    vector<vector<int>>adj;
    int n;
    int mod = 1e9 + 7;
    vector<ll>fact, inv;

    ll power(ll a, ll x) {
        if(x == 0) return 1ll;

        ll temp = power(a, x/2) % mod;
        ll ans = (temp * temp) % mod;
        if(x & 1) ans = (ans * a) % mod;

        return ans % mod;
    }

    pair<ll,ll> dfs(ll node) { // (ways, size of subtree)
        ll ans = 1ll; ll noOfChild = 0ll;
        for(auto it : adj[node]) {
            pair<ll,ll>temp = dfs(it);
            ll tmpWays = temp.first; ll r = temp.second;
            ll comb = ((fact[noOfChild + r] * inv[noOfChild] % mod) * inv[r] % mod) % mod;
            ans = (((ll)ans * tmpWays) % mod) * comb % mod;
            noOfChild += r;
        }

        return {ans, noOfChild + 1};
    }

    int waysToBuildRooms(vector<int>& prevRoom) {
        n = prevRoom.size();
        adj = vector<vector<int>>(n);
        for(int i = 1;i < n;i++) {
            adj[prevRoom[i]].push_back(i);
        }

        fact = vector<ll> (n+1,1);
        inv = vector<ll>(n+1,1);
        for(int i = 2;i <= n;i++) {
            fact[i] = (fact[i-1] * i) % mod;
            inv[i] = power(fact[i], mod - 2);
        }

        return dfs(0).first;
    }
};
