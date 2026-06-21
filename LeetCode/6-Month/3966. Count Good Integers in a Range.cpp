#define ll long long
class Solution {
public:

    ll dp[16][2][11][2];

    ll check(string &s, ll idx, ll n, ll tight, ll prev, ll lz, ll k) {
        if(idx == n) {
            if(lz) return 0ll;
            return 1ll;
        }

        if(dp[idx][tight][prev][lz] != -1ll) return dp[idx][tight][prev][lz];

        ll limit = tight == 1 ?  s[idx] - '0' : 9;

        ll ans = 0ll;
        
        for(ll i = 0;i <= limit;i++) {
            if(i == 0 && lz == 1) {
                ans += check(s, idx + 1, n, tight && (i == limit), prev, lz, k);
            }
            else if(lz == 1) {
                ans += check(s, idx + 1, n, tight && (i == limit), i, 0, k);
            }
            else {
                ll diff = i - prev;
                if(abs(diff) <= k) {
                    ans += check(s, idx + 1, n, tight && (i == limit), i, 0, k);
                }
            }
        }

        return dp[idx][tight][prev][lz] = ans;
    }
    
    long long goodIntegers(long long l, long long r, int k) {
        string right = to_string(r);
        memset(dp, -1ll, sizeof(dp));

        ll ansR = check(right, 0, (ll)right.size(), 1, 10, 1, k);
        
        string left = to_string(l - 1);
        memset(dp, -1ll, sizeof(dp));
        ll ansL = check(left, 0, (ll)left.size(), 1, 10, 1, k);

        return ansR - ansL;
    }
};
