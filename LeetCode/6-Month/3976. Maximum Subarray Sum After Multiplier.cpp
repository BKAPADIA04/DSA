#define ll long long
class Solution {
public:

    ll inf = 1e18;
    
    ll div(ll x, int k) {
        if (x >= 0) return x / k;
        return -((-x) / k);
    }

    ll op(ll x, int k, ll flag) {
        if (flag) return x * k;
        return div(x, k);
    }

    ll f(vector<int>& v, int k, ll flag) {
        int n = v.size();
        vector<ll> dp1(n), dp2(n), dp3(n);

        dp1[0] = v[0], dp2[0] = op(v[0] * 1LL, k, flag);
        dp3[0] = -inf;

        for (int i = 1; i < n; i++) {
            ll val = op(v[i] * 1LL, k, flag);
            dp1[i] = max(1LL * v[i], dp1[i - 1] + v[i]);
            dp2[i] = max({val, dp1[i - 1] + val, dp2[i - 1] + val});
            dp3[i] = max({dp2[i - 1] + v[i], dp3[i - 1] + v[i], dp2[i]});
        }

        ll ans = -inf;
        for (int i = 0; i < n; i++) {
            ans = max({ans, dp1[i], dp2[i], dp3[i]});
        }
        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        ll ans = max(f(nums, k, 0), f(nums, k, 1));
        return ans;
    }
};
