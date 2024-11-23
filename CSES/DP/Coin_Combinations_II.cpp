// #include <bits/stdc++.h>
// using namespace std; 
// #define vt vector
// #define pb push_back
// #define ll long long
// #define ld long double
// #define ar array
// #define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }
// #define print_h(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << " "; }
// #define f(i,s,n) for(ll i=s;i<n;i++)
// #define r(i,s,n) for(ll i=n-1;i>=0;i--)
// #define cf(i,s,n) for(ll i=s;i<=n;i++)
// void yes() { cout<<"YES"<<endl; }
// void no() { cout<<"NO"<<endl; }
// #define MOD 1000000007
// #define endl "\n"
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// #define p pair<ll,ll>

// bool isPerfectSquare(long long x)
// {
//     // Find floating point value of
//     // square root of x.
//     if (x >= 0) {

//         long long sr = sqrt(x);
        
//         // if product of square root 
//         //is equal, then
//         // return T/F
//         return (sr * sr == x);
//     }
//     // else return false if n<0
//     return false;
// }

// ll binpow(ll x, ll y)
// {
//     ll ans = 1;
 
//     while (y > 0)
//     {
//         if (y % 2 == 1)
//             ans *= x;
 
//         x = x * x;
//         y = y / 2;
 
//         x %= MOD;
//         ans %= MOD;
//     }
 
//     return ans;
// }


// ll answer_(vt<ll>& nums, ll n, ll target) {
//     // vector<vector<ll> > dp(n, vector<ll>(target + 1, 0));
//     vector<ll>prev(target+1,0);
//     // Base case initialization
//     for (ll t = 0; t <= target; t++) {
//         prev[t] = (t % nums[0] == 0) ? 1 : 0;
//     }

//     // Fill the dp table iteratively
//         for (ll i = 1; i < n; i++) {
//             vector<ll>curr(target+1,0);
//             for (ll t = 0; t <= target; t++) {
//             ll notTaken = prev[t];
//             ll taken = 0;
//             if (nums[i] <= t) {
//                 taken = curr[t - nums[i]];
//             }
//             curr[t] = (notTaken + taken) % MOD;
//         }
//         prev = curr;
//     }

//     return prev[target];
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     ll n; cin >> n; ll k; cin >> k;
//     vt<ll>nums(n);
//     f(i,0,n) {
//         cin >> nums[i];
//     }
//     vector<vector<ll> >dp(n,vector<ll>(k+1,-1));
//     // sort(nums.begin(),nums.end());
//     // ll ans = answer(nums,dp,n-1,k);
//     // cout << ans << endl;

//     cout << answer_(nums,nums.size(),k) << endl;
// }

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxX = 1e6;
const ll MOD = 1e9+7;

int N, X, c;
ll dp[maxX+1];

int main(){
    scanf("%d %d", &N, &X);

    dp[0] = 1;
    for(int i = 0; i < N; i++){
        scanf("%d", &c);
        for(int j = 0; j <= X-c; j++)
            dp[j+c] = (dp[j+c] + dp[j]) % MOD;
    }

    printf("%lld\n", dp[X]);
}