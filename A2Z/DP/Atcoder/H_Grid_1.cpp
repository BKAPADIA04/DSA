#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll mod = 1e9 + 7;

bool isValid(int m,int n,int x,int y) {
  if(x < 0 || y < 0 || x >= m || y >= n) return false;
  return true;
}

int check(vector<vector<ll> >&nums,vector<vector<ll> >&dp,ll i,ll j) {
  if(i == 0 && j == 0) return 1;
  
  if(dp[i][j] != -1) return dp[i][j];
  
  ll left = 0; int ll up = 0;
  if(j - 1 >= 0 && nums[i][j-1] == 1)
    left = check(nums,dp,i,j-1) % mod;
  if(i - 1 >= 0 && nums[i-1][j] == 1)
    up = check(nums,dp,i-1,j) % mod;
  
  return dp[i][j] = (left + up) % mod;
}

int main() {
  ll m,n; cin >> m >> n;
  vector<vector<ll> >nums(m,vector<ll>(n,0));
  for(ll i = 0;i < m;i++) {
    for(ll j = 0;j < n;j++) {
      char ch; cin >> ch;
      if(ch == '.') nums[i][j] = 1;
    }
  }
//   vector<vector<ll> >dp(m,vector<ll>(n,-1));
  
//   int answer = check(nums,dp,m-1,n-1);
//   cout << answer << endl;



vector<vector<ll> >dp(m,vector<ll>(n,0));
dp[0][0] = 1;

for(ll i = 0; i < m;i++) {
  for(ll j = 0;j < n;j++) {
    if(i == 0 && j == 0) continue;
    ll left = 0; ll up = 0;
    if((j-1 >= 0) && nums[i][j-1] == 1) left = dp[i][j-1] % mod;
    if((i-1 >= 0) && nums[i-1][j] == 1) up = dp[i-1][j] % mod;
    
    dp[i][j] = (left + up) % mod;
  }
}
// cout << dp[m-1][n-1] << endl;


vector<ll>prev(n,0);

for(ll i = 0; i < m;i++) {
  vector<ll>curr(n,0);
  for(ll j = 0;j < n;j++) {
    if(i == 0 && j == 0) { curr[j] = 1;continue; }
    ll left = 0; ll up = 0;
    if((j-1 >= 0) && nums[i][j-1] == 1) left = curr[j-1] % mod;
    if((i-1 >= 0) && nums[i-1][j] == 1) up = prev[j] % mod;
    
    curr[j] = (left + up) % mod;
  }
  prev = curr;
}
cout << prev[n-1] << endl;
}