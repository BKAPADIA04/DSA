//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int find(vector<int>&par,int X) {
        if(par[X] == X) return X;
        else return par[X] = find(par,par[X]);
    }
    
    void unionbyRank(vector<int>&par,vector<int>&rank,int X,int Y) {
        int ult_x = find(par,X);
        int ult_y = find(par,Y);
        if(ult_x == ult_y) return;
        
        if(rank[ult_x] < rank[ult_y]) par[ult_x] = ult_y;
        else if(rank[ult_y] < rank[ult_x]) par[ult_y] = ult_x;
        else {
            par[ult_y] = ult_x;
            rank[ult_x]++;
        }
    }
    
  
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        // PRIMS Algo
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // vector<int>visited(V); 
        
        // pq.push({0,0});
        // int sum = 0;
        
        // while(!pq.empty()) {
        //     int dist = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();
            
        //     if(visited[node]) continue;
        //     visited[node] = 1;
        //     sum += dist;
        //     for(auto it:adj[node]) {
        //         if(!visited[it[0]]) {
        //             pq.push({it[1],it[0]});
        //         }
        //     }
        // }
        // return sum;
        
        // KRUSKAL Algo
        vector<int>par(V,0); vector<int>rank(V,0);
        for(int i = 0;i < V;i++) {
            par[i] = i;
        }
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i = 0;i < V;i++) {
            for(auto edges:adj[i]) {
                pq.push({edges[1],i,edges[0]});
            }
        }
        int sum = 0;
        while(!pq.empty()) {
            auto edge = pq.top(); pq.pop();
            int x = edge[1]; int y = edge[2];
            int wt = edge[0];
            
            if(find(par,x) == find(par,y)) continue;
            sum += wt;
            unionbyRank(par,rank,x,y);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends