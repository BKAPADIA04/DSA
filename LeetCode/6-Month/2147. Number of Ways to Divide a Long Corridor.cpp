#define ll long long
class Solution {
public:

    int n;
    string corridor;
    vector<vector<ll>>dp;
    ll mod;

    ll check(ll i, ll count) {
        if(i >= n) {
            if(count == 2) return 1ll;
            return 0ll;
        }

        if(dp[i][count] != -1) return dp[i][count];

        if(corridor[i] == 'S') {
            count += 1;
        }

        ll ans = 0ll;
        if(count == 2) {
            ans = (ans + check(i+1,0) % mod) % mod;
        }

        if(count <= 2) {
            ans = (ans + check(i+1,count) % mod) % mod;
        } else return 0ll;
        
        return dp[i][count] = ans % mod;
    }

    int numberOfWays(string corridor) {
        n = corridor.size();
        this->corridor = corridor;
        mod = 1e9 + 7;
        dp = vector<vector<ll>>(n,vector<ll>(3,-1));
        return check(0,0);
    }
};
