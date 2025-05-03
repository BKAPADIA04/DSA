#define ll long long 
#include <bits/stdc++.h>
using namespace std;

ll check(vector<ll>&nums,vector<ll>&pre,vector<vector<ll> >&dp,ll i,ll j) {
  ll n = nums.size();
  if(i >= j) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  
  ll mini = LLONG_MAX;
  for(ll k = i;k <= j - 1;k++) {
    ll temp = check(nums,pre,dp,i,k) + check(nums,pre,dp,k+1,j) + (pre[j+1] - pre[i]);
    mini = min(mini,temp);
  }
  
  return dp[i][j] = mini;
}


int main() {
  ll n; cin >> n;
  vector<ll>nums(n);
  for(ll i = 0;i < n;i++) {
    cin >> nums[i];
  }
  
  vector<ll>pre(n+1,0);
  for(ll i = 1;i <= n;i++) {
    pre[i] = pre[i-1] + nums[i-1];
  }
  
  vector<vector<ll> >dp(n,vector<ll>(n,-1));
  cout << check(nums,pre,dp,0,n-1) << endl;
//   for(auto it:pre) cout << it << " ";
  
}