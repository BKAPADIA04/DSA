#define ll long long
class Solution {
public:

    ll n;
    ll k;
    ll dp[100001];
    ll mod = 1e9 + 7;

    ll check(string &s, ll i) {
        if(i == n) return 1ll;
        if(s[i] == '0') return 0ll;

        if(dp[i] != -1ll) return dp[i];

        ll ans = 0ll;

        ll num = 0ll;
        for(ll index = i;index < n;index++) {
            num = num * 10 + (s[index] - '0');

            if(num > k) break;
            
            ans = (ans + check(s, index + 1) % mod) % mod;
        } 

        return dp[i] = ans;
    }

    int numberOfArrays(string s, int k) {
        n = s.size();
        this->k = (ll)k;

        memset(dp, -1ll, sizeof(dp));

        return check(s, 0);
    }
};
