#include <bits/stdc++.h>
  using namespace std;
  
  bool dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&path){
    if(node==0) return 1;
    bool foundRoot=0;
    for(auto ch:adj[node]){
      if(ch!=parent){
        if(dfs(ch,node,adj,path)){
          path.push_back(ch);
          foundRoot=1;
          break;
        }
      }
    }
    
    return foundRoot;
    
  }
  
  long long solve(int node,int parent,vector<vector<int>>&adj,vector<int>&coins){
    long long ans=LLONG_MIN;
    for(auto ch:adj[node]){
      if(ch!=parent){
        ans=max(ans,solve(ch,node,adj,coins));
      }
    }
    if(ans==LLONG_MIN) ans=0; 
    return ans+coins[node];
  }

  int main() {

    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    int r;
    cin>>r;
    r--; // base 0 
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
      int u,v;
      cin>>u>>v;
      u--;v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if(r==0){
      coins[0]=coins[0]>>1;
    }
    else{
      vector<int>pathFromRootToRobber;
      dfs(r,-1,adj,pathFromRootToRobber);
      pathFromRootToRobber.push_back(r); // path root , node... , pathFromRobberToRoot
      
      // updating coin values for this path as the robber mayreach them first
      int m=pathFromRootToRobber.size();
      
      int i=0;
      int j=m-1;
      while(i<=j){
        if(j>i){
          coins[pathFromRootToRobber[j]]=0; // taken by robber
        }
        else if(j==i) coins[pathFromRootToRobber[j]]=coins[pathFromRootToRobber[j]]>>1;
        i++;
        j--;
      }
    // for(auto i:pathFromRootToRobber) cout<<i<<" "<<coins[i]<<endl;
    // cout<<endl;
    }
    
    // maximize the coin sum we can get from 0 
    long long ans=solve(0,-1,adj,coins);
    cout<<ans<<endl;

    return 0;

  }
