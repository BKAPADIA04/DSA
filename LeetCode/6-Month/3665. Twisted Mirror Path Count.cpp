#define ll long long
class Solution {
public:

    ll m,n;
    ll mod = 1e9 + 7;
    vector<vector<int>> grid;
    vector<vector<vector<ll>>>dp;

    bool isValid(ll i, ll j) {
        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        return true;
    }

    ll count(ll i, ll j, ll mirr) {

        if(i == (m - 1) && j == (n-1)) {
            return 1ll;
        }

        if(!isValid(i,j)) return 0ll;

        if(dp[i][j][mirr] != -1ll) return dp[i][j][mirr];

        ll down = 0ll;
        ll right = 0ll;

        if(grid[i][j] == 1) {
            if(mirr == 1) {
                right = count(i,j+1,2) % mod;
            }
            else if(mirr == 2) {
                down = count(i+1,j,1) % mod;
            }
        }

        else {
            if(isValid(i+1,j)) {
                down = count(i+1,j,1) % mod;
            }

            if(isValid(i,j+1)) {
                right = count(i,j+1,2) % mod;
            }
        }

        return dp[i][j][mirr] = (down + right) % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        this->grid = grid;
        dp = vector<vector<vector<ll>>>(m,vector<vector<ll>>(n,vector<ll>(3,-1ll)));
        
        return count(0,0,0) % mod;
    }
};
