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

bool valid(ll i, ll j, ll n) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

ll answer(vector<vector<ll> >&nums,vector<vector<ll> >&dp,ll i,ll j,ll n) {
    if((i == n - 1) && (j == n - 1)) return nums[i][j] == 1;

    if(!valid(i,j,n) || nums[i][j] == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    ll right = 0,down = 0;
    
    if(valid(i,j+1,n) && nums[i][j+1] != 0)
        right = answer(nums,dp,i,j+1,n) % MOD;
    
    if(valid(i+1,j,n) && nums[i+1][j] != 0)
        down = answer(nums,dp,i+1,j,n) % MOD;
    
    return dp[i][j] = (right + down) % MOD;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    vector<vector<ll> >nums(n,vector<ll>(n,1));

    for(ll i = 0;i < n;i++) {
        for(ll j = 0;j < n;j++) {
            char ch; cin >> ch;
            if(ch == '*') nums[i][j] = 0;
        }
    }
    vector<vector<ll> >dp(n,vector<ll>(n,-1));
    cout << answer(nums,dp,0,0,n) << endl;
    
}
