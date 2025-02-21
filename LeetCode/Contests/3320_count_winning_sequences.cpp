#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    ll check(string &s, vector<vector<vector<ll>>>&dp,ll count,ll prev,ll index) {
        if(index == s.size()) {
            if(count > 0) return 1ll;
            return 0ll;
        }

        if(dp[index][count+s.size()][prev] != -1) return dp[index][count+s.size()][prev];

        ll ans = 0ll; ll oppo = -1;
        // if(s[index] == 'F') oppo = 0;
        // else if(s[index] == 'W') oppo = 1;
        // else oppo = 2;

        // for(ll i = 0;i < 3;i++) {
        //     if(prev == i) continue;

        //     if(oppo == 0) {
        //         if(i == oppo) ans += check(s,dp,count,i,index+1) % mod; 
        //         if(i == 1) ans += check(s,dp,count+1,i,index+1) % mod;
        //         if(i == 2) ans += check(s,dp,count-1,i,index+1) % mod;
        //     }

        //     if(oppo == 1) {
        //         if(i == oppo) ans += check(s,dp,count,i,index+1) % mod; 
        //         if(i == 0) ans += check(s,dp,count-1,i,index+1) % mod;
        //         if(i == 2) ans += check(s,dp,count+1,i,index+1) % mod;
        //     }

        //     if(oppo == 2) {
        //         if(i == oppo) ans += check(s,dp,count,i,index+1) % mod; 
        //         if(i == 0) ans += check(s,dp,count+1,i,index+1) % mod;
        //         if(i == 1) ans += check(s,dp,count-1,i,index+1) % mod;
        //     }
        // }

        if(s[index] == 'F') {
            if(prev != 0) ans += check(s,dp,count,0,index+1) % mod; 
            if(prev != 1) ans += check(s,dp,count+1,1,index+1) % mod;
            if(prev != 2) ans += check(s,dp,count-1,2,index+1) % mod;
        }
        else if(s[index] == 'W') {
            if(prev != 0) ans += check(s,dp,count-1,0,index+1) % mod; 
            if(prev != 1) ans += check(s,dp,count,1,index+1) % mod; 
            if(prev != 2) ans += check(s,dp,count+1,2,index+1) % mod; 
        }
        else {
            if(prev != 0) ans += check(s,dp,count+1,0,index+1) % mod; 
            if(prev != 1) ans += check(s,dp,count-1,1,index+1) % mod; 
            if(prev != 2) ans += check(s,dp,count,2,index+1) % mod; 
        }
        return dp[index][count+s.size()][prev] = ans % mod;
    }

    int countWinningSequences(string s) {
        ll n = s.size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(2*n+1,vector<ll>(4,-1ll)));
        return check(s,dp,0,3,0);
    }
};

/*const int MOD = 1e9 + 7;

int solve(string &s) {
    int n = s.size();
    int offset = n; // To handle negative count indexing
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 * n + 1, vector<int>(3, 0)));
    
    // Base case: One valid way to start at index n (count 0)
    dp[0][offset][0] = dp[0][offset][1] = dp[0][offset][2] = 1;
    
    for (int index = 0; index < n; index++) {
        for (int count = -n; count <= n; count++) {
            for (int prev = 0; prev < 3; prev++) {
                int cur_count = count + offset;
                if (dp[index][cur_count][prev] == 0) continue;
                
                if (s[index] == 'F') {
                    if (prev != 0) dp[index + 1][cur_count][0] = (dp[index + 1][cur_count][0] + dp[index][cur_count][prev]) % MOD;
                    if (prev != 1) dp[index + 1][cur_count + 1][1] = (dp[index + 1][cur_count + 1][1] + dp[index][cur_count][prev]) % MOD;
                    if (prev != 2) dp[index + 1][cur_count - 1][2] = (dp[index + 1][cur_count - 1][2] + dp[index][cur_count][prev]) % MOD;
                }
                else if (s[index] == 'W') {
                    if (prev != 0) dp[index + 1][cur_count - 1][0] = (dp[index + 1][cur_count - 1][0] + dp[index][cur_count][prev]) % MOD;
                    if (prev != 1) dp[index + 1][cur_count][1] = (dp[index + 1][cur_count][1] + dp[index][cur_count][prev]) % MOD;
                    if (prev != 2) dp[index + 1][cur_count + 1][2] = (dp[index + 1][cur_count + 1][2] + dp[index][cur_count][prev]) % MOD;
                }
                else {
                    if (prev != 0) dp[index + 1][cur_count + 1][0] = (dp[index + 1][cur_count + 1][0] + dp[index][cur_count][prev]) % MOD;
                    if (prev != 1) dp[index + 1][cur_count - 1][1] = (dp[index + 1][cur_count - 1][1] + dp[index][cur_count][prev]) % MOD;
                    if (prev != 2) dp[index + 1][cur_count][2] = (dp[index + 1][cur_count][2] + dp[index][cur_count][prev]) % MOD;
                }
            }
        }
    }
    
    // Sum up the values in dp[n][offset] for all prev states (final result)
    return (dp[n][offset][0] + dp[n][offset][1] + dp[n][offset][2]) % MOD;
}
*/
