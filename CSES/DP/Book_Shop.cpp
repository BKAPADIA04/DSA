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

// // int main() {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);
// //     cout.tie(0);

    
// //     int n; cin >> n; int k; cin >> k;
// //     vt<int>prices(n);
// //     f(i,0,n) {
// //         cin >> prices[i];
// //     }
// //     vt<int>pages(n);
// //     f(i,0,n) {
// //         cin >> pages[i];
// //     }

// //     vector<vector<int> >dp(n+1,vector<int>(k+1,0));

// //     // for(ll i = prices[0];i <= k;i++) {
// //     //     dp[0][i] = pages[0];
// //     // }

// //     // vector<ll>prev(k+1,0);

// //     // for(ll i = prices[0];i <= k;i++) {
// //     //     prev[i] = pages[0];
// //     // }
// //     for(int index = 1;index <= n;index++) {
// //         // vector<ll>curr(k+1,0);
// //         for(int price = 0;price <= k ;price++) {
// //             int notTaken = dp[index-1][price] ;
// //             int taken = 0;
// //             if(prices[index-1] <= price) {
// //                 taken = (pages[index-1] + dp[index-1][price - prices[index-1]]);
// //             }

// //             dp[index][price] = max(notTaken,taken);
// //         }
// //     }
// //     // for(ll index = 1;index <= n;index++) {
// //     //     for(ll price = 1;price <= k;price++) {
// //     //         cout << dp[index][price] << " ";
// //     //     }
// //     //     cout << endl;
// //     // }
    
// //     cout << dp[n][k] << endl;
// // }

// #include <bits/stdc++.h>
// using namespace std;
 
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
 
//     int t = 1;
//     //cin >> t;
 
//     while (t--)
//     {
//         int n, x, i, j;
//         cin >> n >> x;
 
//         int h[n], s[n];
 
//         for (i = 0; i < n; ++i)
//             cin >> h[i];
 
//         for (i = 0; i < n; ++i)
//             cin >> s[i];
 
//         vector<vector<int> > count(n + 1, vector<int>(x + 1, 0));
 
//         for (i = 1; i <= n; ++i)
//         {
//             for (j = 0; j <= x; ++j)
//             {
//                 count[i][j] = count[i - 1][j];
 
//                 if (j - h[i - 1] >= 0)
//                     count[i][j] = max(count[i][j], count[i - 1][j - h[i - 1]] + s[i - 1]);
//             }
//         }
 
//         cout << count[n][x] << "\n";
//     }
// }

#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000;
const int maxX = 1e5;

int N, X, h[maxN], s[maxN], dp[maxX+1];

int main(){
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++)  scanf("%d", &h[i]);
    for(int i = 0; i < N; i++)  scanf("%d", &s[i]);

    fill(dp+1, dp+X+1, -1);
    for(int i = 0; i < N; i++)
        for(int j = X-h[i]; j >= 0; j--)
            if(dp[j] != -1)
                dp[j+h[i]] = max(dp[j+h[i]], dp[j]+s[i]);

    for(int i = 1; i <= X; i++)
        dp[i] = max(dp[i], dp[i-1]);
    printf("%d\n", dp[X]);
}