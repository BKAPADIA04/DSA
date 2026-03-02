#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;

    ll power(ll x, ll n) {
        if(n == 0) return 1ll;
        ll ans = power(x, n/2) % mod;
        ans = (ans * ans) % mod;
        if(n & 1) ans = (ans * x) % mod;
        return ans;
    }

    int sumOfNumbers(int l, int r, int k) {
        ll sum = 0ll;
        for(ll i = l;i <= r;i++) sum += i;
        ll totalOcc = power(r - l + 1, k - 1);

        ll ans = (sum * totalOcc) % mod;

        ll gp = (power(10,k) - 1 + mod) % mod;
        gp = gp * power(9,mod-2) % mod;

        ans = (ans * gp) % mod;
        return ans;
    }
};
