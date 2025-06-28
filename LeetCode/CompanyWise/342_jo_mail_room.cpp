#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll n; ll m;
vector<vector<ll>>adj;

ll check(ll node, ll parent, ll &answer,vector<ll>&visited) {
  visited[node] = 1;
  ll zeroes = 0ll;
  ll ones = 0ll;
  ll twos = 0ll;
  ll totalChild = 0ll;
  for(auto it : adj[node]) {
    if(it == parent) continue;
    totalChild++;
    ll temp = check(it,node,answer,visited);
    if(temp == 0) zeroes++;
    else if(temp == 1) ones++;
    else twos++;
  }
  
  if(zeroes > 0) {
    answer += 1;
    return 2;
  }
  
  if(zeroes == totalChild) return 0;
  
  if(ones == totalChild) return 0;
  else if(twos == totalChild) return 1;
  else if(ones + twos == totalChild) return 1;
  else {
    answer += 1;
  }
  return 2; // zero bache hai
} 

int main() {
  cin >> n >> m;
  adj = vector<vector<ll>>(n);
  for(int i = 0;i < m;i++) {
    ll a,b;
    cin >> a >> b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  
  ll answer = 0ll;
  vector<ll>visited(n,0);
  for(int i = 0;i < n;i++) {
    if(!visited[i]) {
      visited[i] = 1;
      
      if(check(i,-1,answer,visited) == 0) answer += 1;
    }
  }
  
  cout << answer << endl;
}
