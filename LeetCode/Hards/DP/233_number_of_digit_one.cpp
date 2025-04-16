#define ll long long
class Solution {
public:

    vector<vector<vector<ll>>>dp;

    ll check(string &s, ll index, ll tight, ll count) {
        if(index == s.size()) return count;

        if(dp[index][tight][count] != -1) return dp[index][tight][count];

        ll limit = (tight == 1 ? s[index] - '0' : 9);

        ll ans = 0;

        for(ll i = 0;i <= limit;i++) {
            ll updateCount = count + (i == 1 ? 1 : 0);
            ans += check(s, index + 1, (tight & (i == (s[index] - '0'))) , updateCount);
        }

        return dp[index][tight][count] = ans;
    }


    int countDigitOne(int n) {
        string left = to_string(-1);
        string right = to_string(n);

        dp = vector<vector<vector<ll>>>(11,vector<vector<ll>>(2,vector<ll>(11,-1)));
        
        ll ans_right = check(right, 0, 1, 0);

        return ans_right;
    }
};
