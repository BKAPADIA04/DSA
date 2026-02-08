#define ll long long
class Solution {
public:

    ll n,m;
    vector<int>nums1,nums2;
    vector<vector<vector<ll>>>dp;

    ll check(ll i, ll j, ll k) {
        if(k == 0) return 0ll;
        if(i >= n || j >= m) return LLONG_MIN/2;

        if(dp[i][j][k] != LLONG_MIN) return dp[i][j][k];

        ll skipI = check(i+1,j,k);
        ll skipJ = check(i, j+1,k);

        ll temp = check(i+1,j+1,k-1);

        ll takeBoth = (ll)nums1[i] * (ll)nums2[j] + temp;

        // if(temp != LLONG_MIN/2) {
        //     takeBoth += temp;
        // }
        // ll skipBoth = check(i+1,j+1,k);

        return dp[i][j][k] = max({skipI,skipJ,takeBoth});
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k_) {
        n = nums1.size();
        m = nums2.size();
        ll k = (ll)k_;
        this->nums1 = nums1;
        this->nums2 = nums2;
        dp = vector<vector<vector<ll>>>(n,vector<vector<ll>>(m,vector<ll>(k+1,LLONG_MIN)));
        return check(0,0,k);
    }
};

#define ll long long
class Solution {
public:

    ll n,m;
    vector<int>nums1,nums2;
    vector<vector<vector<ll>>>dp;

    ll check(ll i, ll j, ll k) {
        if(k == 0) return 0ll;
        if(i >= n || j >= m) return LLONG_MIN/2;

        if(dp[i][j][k] != LLONG_MIN) return dp[i][j][k];

        ll skipI = check(i+1,j,k);
        ll skipJ = check(i, j+1,k);

        ll temp = check(i+1,j+1,k-1);

        ll takeBoth = LLONG_MIN/2;

        if(temp != LLONG_MIN/2) {
            takeBoth = (ll)nums1[i] * (ll)nums2[j] + temp;
        }
        // ll skipBoth = check(i+1,j+1,k);

        return dp[i][j][k] = max({skipI,skipJ,takeBoth});
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k_) {
        n = nums1.size();
        m = nums2.size();
        ll k = (ll)k_;
        this->nums1 = nums1;
        this->nums2 = nums2;
        // dp = vector<vector<vector<ll>>>(n,vector<vector<ll>>(m,vector<ll>(k+1,LLONG_MIN)));
        // return check(0,0,k); 
        dp = vector<vector<vector<ll>>>(n+1,vector<vector<ll>>(m+1,vector<ll>(k+1,-1e15)));

        // for(ll p = 0;p <= k;p++) {
        //     for(ll j = 0;j <= m;j++) {
        //         dp[n][j][p] = LLONG_MIN;
        //     }

        //     for(ll i = 0;i <= n;i++) {
        //         dp[i][m][p] = LLONG_MIN;
        //     }
        // }

        for(ll i = 0;i <= n;i++) {
            for(ll j = 0;j <= m;j++) {
                dp[i][j][0] = 0ll;
            }
        }

        for(ll i = n - 1;i >= 0;i--) {
            for(ll j = m - 1;j >= 0;j--) {
                for(ll p = 1;p <= k;p++) {
                    ll skipI = dp[i+1][j][p];
                    ll skipJ = dp[i][j+1][p];

                    ll temp = dp[i+1][j+1][p-1] + (ll)nums1[i] * (ll)nums2[j];
                    // ll takeBoth = LLONG_MIN/2;
                    // if(temp != LLONG_MIN/2) {
                    //     takeBoth = (ll)nums1[i] * (ll)nums2[j] + temp;
                    // }

                    dp[i][j][p] = max({skipI, skipJ, temp});
                }
            }

        }
        return dp[0][0][k];
    }
};
