// // #include <bits/stdc++.h>
// // using namespace std; 
// // #define vt vector
// // #define pb push_back
// // #define ll long long
// // #define ld long double
// // #define ar array
// // #define print(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << endl; }
// // #define print_h(v) for(auto it=v.begin();it!=v.end();it++) { cout << *it << " "; }
// // #define f(i,s,n) for(ll i=s;i<n;i++)
// // #define r(i,s,n) for(ll i=n-1;i>=0;i--)
// // #define cf(i,s,n) for(ll i=s;i<=n;i++)
// // void yes() { cout<<"YES"<<endl; }
// // void no() { cout<<"NO"<<endl; }
// // #define MOD 1000000007
// // #define endl "\n"
// // const ll INF = 0x3f3f3f3f3f3f3f3f;
// // #define p pair<ll,ll>

// // bool isPerfectSquare(long long x)
// // {
// //     // Find floating point value of
// //     // square root of x.
// //     if (x >= 0) {

// //         long long sr = sqrt(x);
        
// //         // if product of square root 
// //         //is equal, then
// //         // return T/F
// //         return (sr * sr == x);
// //     }
// //     // else return false if n<0
// //     return false;
// // }

// // ll binpow(ll x, ll y)
// // {
// //     ll ans = 1;
 
// //     while (y > 0)
// //     {
// //         if (y % 2 == 1)
// //             ans *= x;
 
// //         x = x * x;
// //         y = y / 2;
 
// //         x %= MOD;
// //         ans %= MOD;
// //     }
 
// //     return ans;
// // }

// // void answer(vector<ll>&nums,vector<ll>&dp,ll index,ll &ans) {
// //     if(index == nums.size()) {
// //         ans = ans + 1;
// //         return;
// //     }
// //     if(nums[index] != 0 && index != 0 && abs(nums[index] - nums[index-1]) > 1) return;

// //     if(nums[index] == 0) {
// //         if(index == 0) {
// //             for(ll i = nums[1]-1;i <= nums[1] + 1;i++) {
// //                 nums[0] = i;
// //                 answer(nums,dp,index+1,ans);
// //                 nums[0] = 0;
// //             }
// //         }
// //         else {
// //             for(ll i = nums[index-1]-1;i <= nums[index-1] + 1;i++) {
// //                 nums[index] = i;
// //                 answer(nums,dp,index+1,ans);
// //                 nums[index] = 0;
// //             }
// //         }
// //     }
// // }


// // int main() {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);
// //     cout.tie(0);

// //     ll t = 1;
// //     while(t--) {
// //         ll n; cin >> n; ll k; cin >> k;
// //         vt<ll>nums(n);
// //         f(i,0,n) {
// //             cin >> nums[i];
// //         }
// //         vector<ll>dp;
// //         ll ans = 0;
// //         answer(nums,dp,0,ans);
// //         cout << ans << endl;
// //     }
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define MOD 1000000007
// #define ll long long
// #define vt vector

// // Memoization table
// vector<vector<ll> > memo;

// // Recursive function with memoization
// ll countWays(ll index, ll lastValue, vt<ll>& nums, ll n, ll m) {
//     if (index == n) return 1;  // Reached end of the array, valid path

//     // If already computed, return stored result
//     if (memo[index][lastValue] != -1) return memo[index][lastValue];

//     ll totalWays = 0;

//     // Case when nums[index] is known
//     if (nums[index] != 0) {
//         if (index == 0 || abs(nums[index] - lastValue) <= 1) {
//             totalWays = (totalWays + countWays(index + 1, nums[index], nums, n, m)) % MOD;
//         }
//     }
//     // Case when nums[index] is unknown (0)
//     else {
//         for (ll v = 1; v <= m; v++) {
//             if (index == 0 || abs(v - lastValue) <= 1) {
//                 totalWays = (totalWays + countWays(index + 1, v, nums, n, m)) % MOD;
//             }
//         }
//     }

//     return memo[index][lastValue] = totalWays;  // Store result in memo table
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     ll n, m;
//     cin >> n >> m;
//     vt<ll> nums(n);
//     for (ll i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     // Initialize memo table with -1 (not computed)
//     memo.assign(n, vector<ll>(m + 1, -1));

//     // Calculate the number of ways to form valid arrays
//     ll ans = 0;
//     // Start by setting any valid initial value if nums[0] == 0, otherwise start with nums[0]
//     if (nums[0] == 0) {
//         for (ll v = 1; v <= m; v++) {
//             ans = (ans + countWays(1, v, nums, n, m)) % MOD;
//         }
//     } else {
//         ans = countWays(1, nums[0], nums, n, m);
//     }

//     cout << ans << endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define vt vector

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    vt<ll> nums(n);
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // DP table: dp[i][v] represents the count of valid arrays up to index i with nums[i] = v
    vector<vector<ll> > dp(n, vector<ll>(m + 1, 0));

    // Initialize dp[0][...] based on nums[0]
    if (nums[0] == 0) {
        for (ll v = 1; v <= m; v++) {
            dp[0][v] = 1;  // Any number from 1 to m is allowed if nums[0] is unknown
        }
    } else {
        dp[0][nums[0]] = 1;  // If nums[0] is known, only one way to set it
    }

    // Fill DP table iteratively
    for (ll i = 1; i < n; i++) {
        for (ll v = 1; v <= m; v++) {
            if (nums[i] != 0 && nums[i] != v) continue;  // Skip invalid values if nums[i] is known
            // Add possible values from the previous state
            dp[i][v] = dp[i - 1][v];
            if (v > 1) dp[i][v] = (dp[i][v] + dp[i - 1][v - 1]) % MOD;
            if (v < m) dp[i][v] = (dp[i][v] + dp[i - 1][v + 1]) % MOD;
        }
    }

    // Sum all ways to fill the array at the last index
    ll ans = 0;
    for (ll v = 1; v <= m; v++) {
        ans = (ans + dp[n - 1][v]) % MOD;
    }

    cout << ans << endl;
    return 0;
}
