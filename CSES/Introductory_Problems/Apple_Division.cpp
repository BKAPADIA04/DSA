#include <bits/stdc++.h>
using namespace std; 
#define vt vector
#define pb push_back
#define ll long long
#define ld long double
#define ar array
#define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }
#define print_h(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << " "; }
#define f(i,s,n) for(int i=s;i<n;i++)
#define r(i,s,n) for(int i=n-1;i>=0;i--)
#define cf(i,s,n) for(int i=s;i<=n;i++)
void yes() { cout<<"YES"<<endl; }
void no() { cout<<"NO"<<endl; }
#define MOD 1000000007
#define endl "\n"
const ll INF = 0x3f3f3f3f3f3f3f3f;

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

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     ll n; cin >> n;
//     vt<ll>nums(n);
//     ll totalSum = 0ll;
//     f(i,0,n) {
//         cin >> nums[i];
//         totalSum += nums[i];
//     }
//     // vt<vt<bool> >dp(n,vt<bool>(totalSum + 1,false));

//     vt<bool>prev(totalSum+1,false);

//     prev[0] = true;

//     if(nums[0] <= totalSum) prev[nums[0]] = true;

//     for(ll i = 1; i < n;i++) {
//         vt<bool>curr(totalSum+1,false);
//         curr[0] = true;
//         for(ll sum = 1;sum <= totalSum;sum++) {
//             bool notTaken = prev[sum];
//             bool taken = false;
//             if(nums[i] <= sum) {
//                 taken = prev[sum-nums[i]];
//             }
//             curr[sum] = notTaken || taken;
//         }
//         prev = curr;
//     }
//     // print_h(prev);
//     // for(ll i = 0;i < n;i++) {
//     //     for(ll j = 0;j <= totalSum;j++) {
//     //         cout << dp[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     ll answer = LLONG_MAX;
//     for(ll sum = 1;sum <= totalSum;sum++) {
//         if(prev[sum] == true) {
//             ll s1 = sum;
//             ll s2 = totalSum - s1;
//             answer = min(answer,abs(s1-s2));
//         }
//     }
//     cout << answer << endl;
// }


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    vt<ll>nums(n);
    f(i,0,n) {
        cin >> nums[i];
    }

    ll answer = INF;
    for(ll i = 0;i < (1 << n);i++) {
        ll a = 0,b = 0;
        for(ll j = 0;j < n;j++) {
            if(i & (1 << j)) a += nums[j];
            else b += nums[j];
        }
        answer = min(answer,abs(a-b));
    }
    cout << answer << endl;
}