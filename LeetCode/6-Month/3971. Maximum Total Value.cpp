#define ll long long

class Solution {
public:
    const int M = 1e9 + 7;

    bool check(int md, vector<int>& a, vector<int>& d, int m) {
        ll cnt = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] < md) continue;

            cnt += (a[i] - md) / d[i] + 1;

            if (cnt >= m) return true;
        }

        return false;
    }

    int maxTotalValue(vector<int>& a, vector<int>& d, int m) {
        int st = 1, ed = 1e9;

        while (st <= ed) {
            int md = st + (ed - st) / 2;

            if (check(md, a, d, m))
                st = md + 1;
            else
                ed = md - 1;
        }

        int cutoff = ed;

        ll ans = 0;
        ll cnt = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] < cutoff) continue;

            ll k = (a[i] - cutoff) / d[i] + 1;
            cnt += k;

            ll sum = (k * (2LL * a[i] - (k - 1) * d[i])) / 2;

            ans = (ans + sum % M) % M;
        }

        ll extra = cnt - m;

        ans = (ans - (extra * cutoff) % M + M) % M;

        return ans;
    }
};
