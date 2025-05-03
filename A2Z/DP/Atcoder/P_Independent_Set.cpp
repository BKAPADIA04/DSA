#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll mod = 1e9 + 7;

ll check(vector<vector<ll> >&adj,vector<vector<ll> >&dp,vector<ll>&visited, ll index,ll prev,ll parent) {
//   if(accumulate(visited.begin(),visited.end(),0) == visited.size()) {
//     cout << "here" << endl;
//     return 1;
//   }
  if(dp[index][prev] != -1ll) return dp[index][prev];
  visited[index] = 1;
  ll ans = 1;
  for(auto it:adj[index]) {
    // if(it == parent) continue;
    if(visited[it] == 1) continue;
    // cout << "there" << endl;
    if(prev == 1) ans = (ans * (check(adj,dp,visited,it,0,index) + check(adj,dp,visited,it,1,index)) % mod) % mod;
    if(prev == 0) ans = (ans * check(adj,dp,visited,it,1,index) % mod) % mod;
  }
  visited[index] = 0;
  return dp[index][prev] = ans % mod;
}

int main() {
  ll n; cin >> n;
  vector<vector<ll> >adj(n+1);
  for(ll i = 1;i < n;i++) {
    ll x1,y1; cin >> x1 >> y1;
    adj[x1].push_back(y1);
    adj[y1].push_back(x1);
  }
  
  vector<vector<ll> >dp(n+2,vector<ll>(3,-1));
    vector<ll>visited(n+1,0);
    cout << (check(adj,dp,visited,1,0,-1) + check(adj,dp,visited,1,1,-1)) % mod << endl;
}