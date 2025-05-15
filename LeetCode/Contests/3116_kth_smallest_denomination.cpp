#define ll long long
class Solution {
public:

    ll gcd(ll a, ll b) {
        if(b == 0) return a;
        return gcd(b,a % b);
    }

    ll lcm(ll a,ll b) {
        return a/gcd(a,b) * b;
    }

    ll count(vector<int>&coins, ll x) {
        ll n = coins.size();
        ll sum = 0ll;
        for(ll i = 1;i < (1 << n);i++) {
            // i = mask
            ll setBits = __builtin_popcount(i);
            ll temp_lcm = 1;
            for(ll j = 0;j < n;j++) {
                if(i & (1 << j)) {
                    temp_lcm = lcm(temp_lcm, coins[j]);
                }
            }

            if(setBits & 1) sum += x / temp_lcm;
            else sum -= x / temp_lcm;
        }
        return sum;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll n = coins.size();
        ll ans = 0;
        ll low = 1ll; ll high = 25 * 2e9;
        while(low <= high) {
            ll mid = low + (high - low)/2;
            if(count(coins,mid) >= k) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
