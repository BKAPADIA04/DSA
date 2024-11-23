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

ll maxi(ll n) {
    ll maxi_ = 0;
    ll temp = n;
    while(temp > 0) {
        ll digit = temp % 10;
        maxi_ = max(maxi_,digit);
        temp /= 10;
    }
    return maxi_;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n; ll answer = 0;
    // while(n != 0) {
    //     answer++;
    //     n = n - maxi(n);
    // }
    // cout << answer << endl;

    // or DP soln
    vector<ll>dp(n+1,INT_MAX);
    dp[0] = 0;
    for(ll i = 1;i <= n;i++) {
        ll temp = i;
        while(temp > 0) {
            if(temp % 10 != 0) {
                dp[i] = min(dp[i],dp[i-(temp % 10)] + 1);
            }
            temp /= 10;
        }
    }
    cout << dp[n] << endl;
}