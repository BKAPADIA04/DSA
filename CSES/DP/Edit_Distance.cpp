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

    string str1,str2; cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    vector<vector<int> >dp(n+1,vector<int>(m+1,0));
    for(int i = 1;i <= n;i++) dp[i][0] = i;
    for(int j = 1;j <= m;j++) dp[0][j] = j;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(str1[i-1] == str2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
            else dp[i][j] = min(1 + dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
        }
    }
    int ans = dp[n][m];

    cout << ans << endl;
}