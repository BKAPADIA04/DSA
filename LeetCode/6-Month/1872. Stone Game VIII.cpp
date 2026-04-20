#define ll long long
class Solution {
public:

    int n;
    vector<ll>prefix;
    vector<int>stones;
    ll dp[100001][2];

    ll check(ll i, ll option) {
        if(i == n - 1) {
            if(option == 0) return prefix[n];
            return -prefix[n];
        }

        if(dp[i][option] != -1) return dp[i][option];

        ll ans;
        ll opt1, opt2;

        if(option == 0) {
            opt1 = check(i+1, option);
            opt2 = prefix[i+1] + check(i+1, 1 - option);

            ans = max(opt1, opt2);
        }
        else {
            opt1 = check(i+1, option);
            opt2 = -prefix[i+1] + check(i+1, 1 - option);
            
            ans = min(opt1, opt2);
        }

        return dp[i][option] = ans;
    }


    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        prefix = vector<ll>(n + 1,0ll);
        this->stones = stones;
        for(int i = 1;i <= n;i++) {
            prefix[i] = prefix[i-1] + (ll)stones[i-1];
        }
        memset(dp, -1ll, sizeof(dp));
        return check(1,0);
    }
};
