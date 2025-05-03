#include <bits/stdc++.h>
using namespace std;

vector<int> kuhn(vector<vector<int> >&adj) {
  int n = adj.size();
  vector<int>indegree(n,0);
  for(auto it:adj) {
    for(auto it1:it) {
      indegree[it1]++;
    }
  }
  
  queue<int>q;
  for(int i = 1;i < n;i++) {
    if(indegree[i] == 0) q.push(i);
  }
  
  vector<int>topo;
  while(!q.empty()) {
    int node = q.front(); q.pop();
    topo.push_back(node);
    
    for(auto it:adj[node]) {
      indegree[it]--;
      if(indegree[it] == 0) q.push(it);
    }
  }
  return topo;
}

int check(vector<vector<int> >&adj,vector<int>&dp) {
  vector<int>topo = kuhn(adj);
  for(auto it:topo) {
    for(auto it1:adj[it]) {
      dp[it1] = max(dp[it1],1 + dp[it]);
    }
  }
  return *max_element(dp.begin(),dp.end());
}


int main() {
  int n,m; cin >> n >> m;
  vector<vector<int> >adj(n+1);
  for(int i = 0;i < m;i++) {
    int u,v; cin >> u >> v;
    adj[u].push_back(v);
  }
  vector<int>topo = kuhn(adj);
  vector<int>dp(n+1,0);
  cout << check(adj,dp) << endl;
  
//   vector<int>visited(n+1,0),dp(n+1,-1); int answer = 0;
//   for(int i = 1;i <= n;i++) {
//     if(!visited[i]) {
//       answer = max(answer,dfs(adj,dp,visited,i));
//     }
//   }
//   cout << answer << endl;
//   return 0;
}