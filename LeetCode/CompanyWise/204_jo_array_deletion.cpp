#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<vector<ll>>>>dp;

ll check(int i, int p, int q, int r, vector<int>&nums) {
  int n = nums.size();
  if(i == n) {
    if(p == 0 && q == 0 && r == 0) return 0;
    return 1e9;
  }
  
  if(dp[i][p][q][r] != -1) return dp[i][p][q][r];
  
  ll ans = check(i+1,p,q,r,nums);
  if(p > 0) ans = min(ans,(ll)nums[i] + check(i+1,p-1,q,r,nums));
  if(q > 0 && i + 1 < n) ans = min(ans,(ll)nums[i] + (ll)nums[i+1] + check(i+2,p,q-1,r,nums));
  if(r > 0 && i + 2 < n) ans = min(ans,(ll)nums[i] + (ll)nums[i+1] + (ll)nums[i+2] + check(i+3,p,q,r-1,nums));
  return dp[i][p][q][r] = ans;
}

int main() {
  int n,p,q,r;
  cin >> n >> p >> q >> r;
  vector<int>nums(n);
  for(int i = 0;i < n;i++) cin >> nums[i];
  dp = vector<vector<vector<vector<ll>>>>(n,vector<vector<vector<ll>>>(p+1,vector<vector<ll>>(q+1,vector<ll>(r + 1,-1))));
  ll sum = accumulate(nums.begin(),nums.end(),0);
  ll ans = check(0,p,q,r,nums);
  cout << sum - ans << endl;
}
