#define ll long long
class Solution {
public:

    ll m,n;
    ll k;
    ll mod;
    vector<vector<int>> grid;
    vector<vector<vector<ll>>>dp;

    ll check(ll i, ll j, ll modulus) {
        if(i == (m - 1) && j == (n - 1)) {
            if((modulus + (ll)grid[i][j]) % k == 0) return 1ll;
            return 0ll;
        }

        if(dp[i][j][modulus] != -1ll) return dp[i][j][modulus];

        ll right = 0ll; ll down = 0ll;
        ll newMod = (modulus + (ll)grid[i][j]) % k;
        if(i + 1 < m) {
            down = check(i + 1, j, newMod) % mod;
        }

        if(j + 1 < n) {
            right = check(i, j + 1, newMod) % mod;
        }

        return dp[i][j][modulus] = (right + down) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        this->k = (ll)k;
        this->grid = grid;
        mod = 1e9 + 7;
        dp = vector<vector<vector<ll>>>(m,vector<vector<ll>>(n,vector<ll>(k,-1ll)));
        return check(0,0,0) % mod;
    }
};
