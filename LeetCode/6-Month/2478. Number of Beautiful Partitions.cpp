#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;
    ll n;
    int minLength;
    ll dp[1001][1001];

    ll check(string &s, ll i, int k) {
        if(i == n) {
            return k == 0;
        }

        if(k < 0) return 0ll;

        if(dp[i][k] != -1ll) return dp[i][k]; 

        ll number = s[i] - '0';
        if(number == 1 || number == 4 || number == 6 || number == 8 || number == 9) return 0ll;

        ll ans = 0ll;

        for(ll index = i + (ll)minLength - 1ll;index < n;index++) {
            ll num = s[index] - '0';
            if(num == 1 || num == 4 || num == 6 || num == 8 || num == 9) {
                ans = (ans + check(s, index + 1, k - 1) % mod) % mod;
            }
        }

        return dp[i][k] = ans;
    }

    int beautifulPartitions(string s, int k, int minLength) {
        n = s.size();
        this->minLength = minLength;
        memset(dp, -1ll, sizeof(dp));
        return check(s, 0, k);
    }
};
