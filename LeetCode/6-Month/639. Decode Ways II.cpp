#define ll long long
class Solution {
public:

    int n;
    string s;
    ll mod;
    vector<ll>dp;

    // vector<vector<vector<int>>>dp;

    // int check(int i, int value, int isZero) {
    //     if(i >= n) {
    //         if(value >= 1 && value <= 26 && !isZero) return 1ll;
    //         return 0ll;
    //     }

    //     if(dp[i][value][isZero + 1] != -1) return dp[i][value][isZero + 1];

    //     // cout << i << " " << value << " " << isZero << endl;

    //     int ans = 0;
    //     if(isZero != -1) {
    //         if(s[i] != '*') {
    //             int opt1Val = value * 10 + (s[i] - '1') + 1;
    //             if(!isZero && opt1Val <= 26) {
    //                 // cout << i << " " << opt1Val << endl;
    //                 ans = (ans + check(i+1, opt1Val,isZero) % mod) % mod;
    //             }
    //         }
    //         else {
    //             for(int j = 1;j <= 9;j++) {
    //                 int opt1Val = value * 10 + j;
    //                 if(!isZero && opt1Val <= 26) {
    //                     // cout << i << " " << opt1Val << endl;
    //                     ans = (ans + check(i+1, opt1Val,isZero) % mod) % mod;
    //                 }
    //             }
    //         }
    //     }

    //     if(s[i] != '*') {
    //         int opt2Val = (s[i] - '1') + 1;
    //         int newIsZero = 0;
    //         if(s[i] == '0') newIsZero = 1;

    //         if(!newIsZero && opt2Val <= 26) {
    //             ans = (ans + check(i+1, opt2Val,newIsZero) % mod) % mod;
    //         }
    //     }
    //     else {
    //         for(int j = 1;j <= 9;j++) {
    //             ans = (ans + check(i+1,j,0) % mod) % mod;
    //         }
    //     }

    //     return dp[i][value][isZero + 1] = ans % mod;
    // }

    ll count(ll i) {
        if(i < 0) return 1ll;

        if(dp[i] != -1ll) return dp[i];

        if(s[i] == '*') {
            ll res = 9 * count(i-1) % mod;

            if(i > 0 && s[i-1] == '1') {
                res = (res + 9 * count(i-2)) % mod;
            }
            else if(i > 0 && s[i-1] == '2') {
                res = (res + 6 * count(i-2)) % mod;
            }
            else if(i > 0 && s[i-1] == '*') {
                res = (res + 15 * count(i-2)) % mod;
            }

            return dp[i] = res;
        }

        ll res = s[i] != '0' ? count(i-1) : 0;

        if(i > 0 && s[i-1] == '1') {
            res = (res + count(i-2)) % mod;
        }
        else if(i > 0 && s[i-1] == '2' && s[i] <= '6') {
            res = (res + count(i-2)) % mod;
        }
        else if(i > 0 && s[i-1] == '*') {
            res = (res + (s[i] <= '6' ? 2 : 1) * count(i-2)) % mod;
        }

        return dp[i] = res;
    }

    int numDecodings(string s) {
        n = s.size();
        this->s = s;
        mod = 1e9 + 7;
        // dp = vector<vector<vector<int>>>(n,vector<vector<int>>(27,vector<int>(3,-1)));
        // return check(0,0,-1);
        dp = vector<ll>(n,-1);
        return count(n-1);

    }
};
