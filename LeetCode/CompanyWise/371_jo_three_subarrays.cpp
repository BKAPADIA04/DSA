#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
  ll t; cin >> t;
  while(t--) {
    ll n; cin >> n;
    vector<ll>nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    
    vector<vector<ll>>dp(n,vector<ll>(5,-1e18));
    dp[0][0] = nums[0];
    for(int i = 1;i < n;i++) {
      dp[i][0] = dp[i-1][0] + nums[i];
      dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
      dp[i][2] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + nums[i];
      dp[i][3] = max(dp[i-1][2],dp[i-1][3]);
      dp[i][4] = max({dp[i-1][2], dp[i-1][3],dp[i-1][4]}) + nums[i];
    }
    
    cout << dp[n-1][4] << endl;
  }
}
