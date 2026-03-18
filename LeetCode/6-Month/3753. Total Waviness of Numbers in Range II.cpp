#define ll long long
class Solution {
public:

    ll dp[17][2][2][11][11][17];


    ll check(string &s, ll idx, ll tight, ll lz, ll lastPrev, ll prev, ll count) {
        if(idx == (ll)s.size()) {
            if(lz) return 0ll;
            if(lastPrev != 10 && prev != 10) return count;
            return 0;
        }

        if(dp[idx][tight][lz][lastPrev][prev][count] != -1) return dp[idx][tight][lz][lastPrev][prev][count];

        ll limit = tight ? s[idx] - '0' : 9;
        ll ans = 0ll;
        for(ll i = 0;i <= limit;i++) {
            if(lz && (i == 0)) {
                ans += check(s, idx + 1, tight && (i == (s[idx] - '0')), lz, lastPrev, prev, count);
            }
            else if(lz) {
                ans += check(s, idx + 1, tight && (i == (s[idx] - '0')), 0, prev, i, count); // (10,i)
            }
            else if(lastPrev == 10){
                ans += check(s, idx + 1, tight && (i == (s[idx] - '0')), 0, prev, i, count); // (prev, i)
            }
            else {
                ll updatedCnt = count;
                if((lastPrev < prev && prev > i) || (lastPrev > prev && prev < i)) {
                    updatedCnt += 1;
                }
                ans += check(s, idx + 1, tight && (i == (s[idx] - '0')), 0, prev, i, updatedCnt); // (prev, i)
            }
        }

        return dp[idx][tight][lz][lastPrev][prev][count] = ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        string right = to_string(num2);
        memset(dp, -1, sizeof(dp));
        ll rightAns = check(right, 0, 1, 1, 10, 10, 0);

        string left = to_string(num1 - 1);
        memset(dp, -1, sizeof(dp));
        ll leftAns = check(left, 0, 1, 1, 10, 10, 0);

        return rightAns - leftAns;
    }
};
