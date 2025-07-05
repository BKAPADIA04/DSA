#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll mod = 1e6 + 7;

ll check(string &s, ll index, ll tight, ll xorSum, ll minimum, ll maximum,ll lead, ll dp[19][2][16][10][10][2]) {
  
  if(index == s.size()) {
    double avg = (minimum + maximum) / 2.0;
    if((double)xorSum > avg) return 1;
    return 0;
  }
  
  ll &res = dp[index][tight][xorSum][minimum][maximum][lead];
  if(res != -1) return res;
  
  ll upperLimit = (tight == 1 ? s[index] - '0' : 9);
  res = 0;
  
  for(ll i = 0;i <= upperLimit;i++) {
    
    ll newXorSum = xorSum ^ i;
    ll newLead = lead & (i == 0);
    ll mini = (newLead == 1 ? minimum : min(i,minimum));
    ll maxi = max(maximum,i);
    
    res = res + (check(s, index + 1, (tight & (i == upperLimit)), newXorSum, mini, maxi,newLead, dp) % mod) % mod;
  }
  
  return res;
}

int main() {
  ll num1; cin >> num1;
  ll num2; cin >> num2;
  
  string s1 = to_string(num1 - 1);
  string s2 = to_string(num2);
  
  ll dp1[19][2][16][10][10][2];
  memset(dp1,-1,sizeof(dp1));
  ll ans2 = check(s2,0,1,0,9,0,1,dp1);
  
  ll dp2[19][2][16][10][10][2];
  memset(dp2,-1,sizeof(dp2));
  ll ans1 = check(s1,0,1,0,9,0,1,dp2);
  
  cout << (ans2 - ans1 + mod) % mod<< endl;
  return 0;
}
