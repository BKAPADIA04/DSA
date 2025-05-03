#define ll long long
#include <bits/stdc++.h>
using namespace std;

double check(ll n, vector<vector<vector<double> > >&dp,ll freq1,ll freq2,ll freq3) {
  if(freq1 == 0 && freq2 == 0 && freq3 == 0) { return 0.0;}
  
  if(dp[freq1][freq2][freq3] != -1.0) return dp[freq1][freq2][freq3];
  
  double ans = 1.0;
  if(freq1 > 0) ans += (1.0 * freq1 / n) * check(n,dp,freq1-1,freq2,freq3) * 1.0;
  if(freq2 > 0) ans += (1.0 * freq2 / n) * check(n,dp,freq1+1,freq2-1,freq3) * 1.0;
  if(freq3 > 0) ans += (1.0 * freq3 / n) * check(n,dp,freq1,freq2+1,freq3-1) * 1.0;
  
  double p0 = ((n - freq1 - freq2 - freq3) / (n * 1.0));
  
  double prob = ((1.0 * ans)/(1.0-p0)) * 1.0;
  return dp[freq1][freq2][freq3] = prob;
}

int main() {
  ll n; cin >> n;
  vector<ll>nums;
  vector<ll>freq(4,0);
  for(ll i = 0;i < n;i++) {
    ll ele; cin >> ele; nums.push_back(ele);
    freq[ele]++;
  }
  
  vector<vector<vector<double> > >dp(302+2,vector<vector<double> >(302+2,vector<double>(302+2,-1.0)));
  cout << setprecision(10) << check(n,dp,freq[1],freq[2],freq[3]) << endl;
  
}