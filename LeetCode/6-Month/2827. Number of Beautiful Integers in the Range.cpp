#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:

    ll dp[11][2][2][25][21];
    int k;

    ll check(string &str, ll idx, ll tight, ll lz, ll even, ll rem) {
        if(idx == (str.size())) {
            if(lz) return 0ll;
            if(even == 0 && rem == 0) return 1ll;
            return 0ll;
        }

        if(dp[idx][tight][lz][even + 11][rem] != -1) return dp[idx][tight][lz][even + 11][rem];
        ll limit = tight == 1 ? str[idx] - '0' : 9;

        ll answer = 0ll;
        
        for(ll i = 0;i <= limit;i++) {
            if(lz && i == 0) {
                answer += check(str, idx + 1, tight & (i == (str[idx] - '0')), lz, even, rem);
            }
            else if(lz) {
                ll newEven = even;
                if(i & 1) newEven -= 1;
                else newEven += 1;
                answer += check(str, idx + 1, tight & (i == (str[idx] - '0')), 0, newEven, i % k);
            }
            else {
                ll newEven = even;
                if(i & 1) newEven -= 1;
                else newEven += 1;
                ll newRem = (rem * 10 + i) % k;

                answer += check(str, idx + 1, tight & (i == (str[idx] - '0')), lz, newEven, newRem);
            }
        }

        return dp[idx][tight][lz][even + 11][rem] = answer;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        this->k = k;
        string right = to_string(high);
        memset(dp,-1ll,sizeof(dp));
        ll rightAns = check(right, 0, 1, 1, 0, 0);

        string left = to_string(low - 1);
        memset(dp,-1ll,sizeof(dp));
        ll leftAns = check(left, 0, 1, 1, 0, 0);

        return rightAns - leftAns;
    }
};
