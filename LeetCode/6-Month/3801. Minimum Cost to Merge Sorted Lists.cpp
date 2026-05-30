#define ll long long
class Solution {
public:
    ll m;
    vector<ll>medians, lengths;
    vector<ll>dp;
    ll sz;

    void assignMedians(vector<vector<int>>& lists) {
        for(ll i = 1;i < sz;i++) {
            vector<ll>tmp;
            for(ll j = 0;j < m;j++) {
                if(i & (1LL << j)) {
                    for(ll k = 0;k < (ll)lists[j].size();k++) tmp.push_back(lists[j][k]);
                }
            }
            // sort(tmp.begin(), tmp.end());
            ll len = tmp.size();
            ll mid = (len - 1)/2;
            nth_element(tmp.begin(), tmp.begin() + mid, tmp.end());
            medians[i] = tmp[mid];
            lengths[i] = len;
        }
    }

    ll check(ll mask) {
        if(__builtin_popcount(mask) == 1) return 0ll;

        if(dp[mask] != -1) return dp[mask];

        ll ans = LLONG_MAX;
        for(ll sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
            ll other = mask ^ sub;
            if(other == 0) continue;
            if(sub > other) continue;

            ll cost = check(sub) + check(other) + lengths[mask] + abs(medians[sub] - medians[other]);

            ans = min(ans, cost);
        }
        return dp[mask] = ans;
    }

    long long minMergeCost(vector<vector<int>>& lists) {
        m = lists.size();
        sz = 1LL << m;
        medians = vector<ll>(sz,0);
        lengths = vector<ll>(sz,0);
        dp = vector<ll>(sz, -1ll);
        assignMedians(lists);


        return check(sz - 1);
    }
};
