//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    void dfs(stack<int>&s,vector<int>&visited,int i,vector<vector<pair<int,int>>>& adj) {
        visited[i] = 1;
        for(auto ch:adj[i]) {
            if(visited[ch.first] == 0) 
                dfs(s,visited,ch.first,adj);
        }
        s.push(i);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        stack<int>s;
        vector<vector<pair<int,int>>>adj(V);
        for(int i = 0;i < E;i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int>visited(V,0);
        for(int i = 0; i < V;i++) {
            if(visited[i] == 0) dfs(s,visited,i,adj);
        }
        vector<int>ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        vector<int>dist(V,INT_MAX);
        queue<int>q;
        q.push(0);
        dist[0] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto ch:adj[u]) {
                int v = ch.first;
                int wt = ch.second;
                
                if(dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    q.push(v);
                }
            }
        }
        for(int i = 0;i < V;i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends