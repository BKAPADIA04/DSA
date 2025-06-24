#include <bits/stdc++.h>
  using namespace std;

  int main() {
   int n,m,k;
   cin>>n>>m>>k;
   unordered_map<int,vector<vector<int>>> adj;
   for(int i=0;i<m;i++){
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
   }
   int ans=INT_MAX;
   priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int price=curr[0];
            int node=curr[1];
            int stops=curr[2];
            if(stops>k) continue;
            if(node==n-1){
              ans=min(ans,price);
               continue;
            }
            for(auto v:adj[node]){
               int mid=v[0];
               if(price>v[1]){
                 pq.push({price,mid,stops+1});
               }else{
                 pq.push({v[1],mid,stops+1});
               }
            }
        }
        if(ans==INT_MAX) ans=-1;
        cout<<ans<<endl;
    return 0;

  }
