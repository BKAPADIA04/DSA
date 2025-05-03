#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll check(vector<ll>&nums,vector<vector<vector<ll> > >&dp,ll i,ll j,ll opt) {
    if(i > j) return 0;
    if(dp[i][j][opt] != -1) return dp[i][j][opt];
  
    if(!opt) {
        ll opt1 = nums[i] + check(nums,dp,i+1,j,1 - opt);
        ll opt2 = nums[j] + check(nums,dp,i,j-1,1 - opt);
    
        return dp[i][j][opt] = max(opt1,opt2);
    }

    ll opt1 = -nums[i] + check(nums,dp,i+1,j,1 - opt);
    ll opt2 = -nums[j] + check(nums,dp,i,j-1,1 - opt);
  
    return dp[i][j][opt] = min(opt1,opt2);
}

int main() {
  ll n; cin >> n;
  vector<ll>nums;
  for(ll i = 0;i < n;i++) {
    ll ele; cin >> ele;
    nums.push_back(ele);
  }
  
  vector<vector<vector<ll> > >dp(n,vector<vector<ll> >(n,vector<ll>(2,-1)));
  cout << check(nums,dp,0,n-1,0) << endl;
}