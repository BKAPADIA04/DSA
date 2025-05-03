#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll check(vector<ll>&weights,vector<ll>&values,vector<vector<ll> >&dp,ll index,ll value) {
    if(value == 0) return 0;
    if(value < 0) return LLONG_MAX;
    if(index == 0) {
        if(values[index] == value) return weights[index];
        return LLONG_MAX;
    }
  
  if(dp[index][value] != -1) return dp[index][value];
  
  ll notTaken = check(weights,values,dp,index-1,value);
  ll taken = LLONG_MAX;
  if(values[index] <= value) {
    ll temp2 = check(weights,values,dp,index-1,value - values[index]);
    if(temp2 != LLONG_MAX) {
      taken = weights[index] + temp2;
    }
  }
  return dp[index][value] = min(notTaken,taken);
}

int main() {
  ll n; cin >> n; ll w; cin >> w;
  vector<ll>weights(n,0),values(n,0);
  for(ll i = 0;i < n;i++) {
    ll ele1,ele2; cin >> ele1 >> ele2;
    weights[i] = ele1; values[i] = ele2;
  }
  
  ll ans = 0;
//   vector<vector<ll> >dp(n,vector<ll>(8+1,-1));
//   check(weights,values,dp,n-1,8);
//   print(dp);

vector<vector<ll> >dp(n,vector<ll>(1e5+1,-1));
  for(ll i = 1e5;i >= 1;i--) {
    if(check(weights,values,dp,n-1,i) <= w) {
      ans = i; break;
    }
  }
    cout << ans << endl;
}