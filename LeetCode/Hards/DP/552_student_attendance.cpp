#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;

    ll check(vector<vector<vector<ll>>>&dp,ll index,ll absent,ll late) {
        if(index == dp.size()) return 1;
        if(absent > 1 || late >= 3) return 0;

        if(dp[index][absent][late] != -1) return dp[index][absent][late];

        ll present = check(dp,index+1,absent,0) % mod;
        ll abs = 0;
        if(absent + 1 <= 1) {
            abs = check(dp,index+1,absent+1,0) % mod;
        }
        ll lat = 0;
        if(late + 1 <= 2) {
            lat = check(dp,index+1,absent,late+1) % mod;
        }

        return dp[index][absent][late] = (present + abs + lat) % mod;
    }

    int checkRecord(int n) {
        // vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(2,vector<ll>(4,-1ll)));
        // return check(dp,0,0,0);

        // vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(2,vector<ll>(4,0)));
        // for(ll j = 0;j < 2;j++) {
        //     for(ll k = 0;k < 4;k++) {
        //         dp[n][j][k] = 1;
        //     }
        // }
        vector<vector<ll>>next(2,vector<ll>(4,1));
        vector<vector<ll>>curr(2,vector<ll>(4,0));

        for(ll i = n - 1;i >= 0;i--) {
            for(ll j = 1;j >= 0;j--) {
                for(ll k = 3;k >= 0;k--) {
                    ll present = next[j][0] % mod;
                    ll abs = 0,lat = 0;
                    if(j + 1 <= 1) {
                        abs = next[j+1][0] % mod;
                    }
                    if(k + 1 <= 2) {
                        lat = next[j][k+1] % mod;
                    }

                    curr[j][k] = (present + abs + lat) % mod;
                }
            }
            next = curr;
        }
       return next[0][0];
    }
};


/*
#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;

    ll check(vector<vector<vector<ll>>>&dp,ll index,ll absent,ll late) {
        if(index == dp.size()) return 1;
        if(absent > 1 || late >= 3) return 0;

        if(dp[index][absent][late] != -1) return dp[index][absent][late];

        ll present = check(dp,index+1,absent,0) % mod;
        ll abs = 0;
        if(absent + 1 <= 1) {
            abs = check(dp,index+1,absent+1,0) % mod;
        }
        ll lat = 0;
        if(late + 1 <= 2) {
            lat = check(dp,index+1,absent,late+1) % mod;
        }

        return dp[index][absent][late] = (present + abs + lat) % mod;
    }

    int checkRecord(int n) {
        // vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(2,vector<ll>(4,-1ll)));
        // return check(dp,0,0,0);

        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(2,vector<ll>(4,0)));
        for(ll j = 0;j < 2;j++) {
            for(ll k = 0;k < 4;k++) {
                dp[n][j][k] = 1;
            }
        }

        for(ll i = n - 1;i >= 0;i--) {
            for(ll j = 1;j >= 0;j--) {
                for(ll k = 3;k >= 0;k--) {
                    ll present = dp[i+1][j][0] % mod;
                    ll abs = 0,lat = 0;
                    if(j + 1 <= 1) {
                        abs = dp[i+1][j+1][0] % mod;
                    }
                    if(k + 1 <= 2) {
                        lat = dp[i+1][j][k+1] % mod;
                    }

                    dp[i][j][k] = (present + abs + lat) % mod;
                }
            }
        }
       return dp[0][0][0];
    }
};*/
