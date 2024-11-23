#include <bits/stdc++.h>
using namespace std; 
#define vt vector
#define pb push_back
#define ll long long
#define ld long double
#define ar array
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }
#define print_h(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << " "; }
#define f(i,s,n) for(ll i=s;i<n;i++)
#define r(i,s,n) for(ll i=n-1;i>=0;i--)
#define cf(i,s,n) for(ll i=s;i<=n;i++)
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }
#define MOD 1000000007
#define endl "\n"
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define p pair<ll,ll>

bool isPerfectSquare(long long x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {

        long long sr = sqrt(x);
        
        // if product of square root 
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

ll binpow(ll x, ll y)
{
    ll ans = 1;
 
    while (y > 0)
    {
        if (y % 2 == 1)
            ans *= x;
 
        x = x * x;
        y = y / 2;
 
        x %= MOD;
        ans %= MOD;
    }
 
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    while(t--) {
        ll n; cin >> n; ll m; cin >> m;
        vector<vector<ll> >dp(n+1,vector<ll>(m+1,1e9));

        for(ll i = 0;i <= min(n,m);i++) {
            dp[i][i] = 0;
        }

        for(ll i = 1;i <= n;i++) {
            for(ll j = 1;j <= m;j++) {
                
                if(i == j) continue;
                
                // Vertical cuts
                for(ll k = 1;k < j;k++) {
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[i][j-k] + 1);
                }

                // Horizontal cuts
                for(ll k = 1;k < i;k++) {
                    dp[i][j] = min(dp[i][j],dp[k][j] + dp[i-k][j] + 1);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}