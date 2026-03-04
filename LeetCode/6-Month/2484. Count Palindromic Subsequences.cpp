#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;
    string s;
    ll n;
    ll dp[10002][11][11][7];
    
    ll check(ll first, ll second, ll cnt, ll i) {
        if(i == n) {
            if(cnt == 6) return 1ll;
            return 0ll;
        }

        // cout << first << " " << second << endl;

        if(dp[i][first+1][second+1][cnt] != -1ll) return dp[i][first+1][second+1][cnt];

        ll answer = check(first, second, cnt, i + 1) % mod;

        if(cnt == 1) {
            ll temp = s[i] - '0';
            answer = (answer + check(temp,second,cnt+1,i+1) % mod) % mod;
        }
        else if(cnt == 2) {
            ll temp = s[i] - '0';
            answer = (answer + check(first,temp,cnt+1,i+1) % mod) % mod;
        }
        else if(cnt == 3) {
            ll temp = s[i] - '0';
            answer = (answer + check(first,second,cnt+1,i+1) % mod) % mod;
        }
        else if(cnt == 4 && ((s[i] - '0') == second)) {
            answer = (answer + check(first,second,cnt+1,i+1) % mod) % mod;
        }
        else if(cnt == 5 && ((s[i] - '0') == first)) {
            answer = (answer + check(first,second,cnt+1,i+1) % mod) % mod;
        }

        return dp[i][first+1][second+1][cnt] = answer % mod;
    }

    int countPalindromes(string s) {
        this->s = s;
        n = s.size();
        memset(dp,-1ll,sizeof(dp));
        return check(-1,-1,1,0) % mod;
    }
};

/*int pre[10000][10][10], suf[10000][10][10], cnts[10] = {};
int countPalindromes(string s) {
    int mod = 1e9 + 7, n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';
        if (i)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++) {
                    pre[i][j][k] = pre[i - 1][j][k];
                    if (k == c) pre[i][j][k] += cnts[j];
                }
        cnts[c]++;
    }
    memset(cnts, 0, sizeof(cnts));
    for (int i = n - 1; i >= 0; i--) {
        int c = s[i] - '0';
        if (i < n - 1)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++) {
                    suf[i][j][k] = suf[i + 1][j][k];
                    if (k == c) suf[i][j][k] += cnts[j];
                }
        cnts[c]++;
    }
    for (int i = 2; i < n - 2; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                ans = (ans + 1LL * pre[i - 1][j][k] * suf[i + 1][j][k]) % mod;
    return ans;
}*/
