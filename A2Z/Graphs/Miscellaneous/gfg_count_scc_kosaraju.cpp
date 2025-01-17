//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
  public:
    
    void dfs(vector<vector<int>>&adj,vector<int>&visited,int i,stack<int>&s) {
        visited[i] = 1;
        for(auto it:adj[i]) {
            if(!visited[it]) {
                dfs(adj,visited,it,s);
            }
        }
        s.push(i);
    }
    
    void dfs_rev(vector<vector<int>>&adj1,vector<int>&visited,int i) {
        visited[i] = 1;
        for(auto it:adj1[i]) {
            if(!visited[it]) {
                dfs_rev(adj1,visited,it);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>visited(n);
        stack<int>s;
        for(int i = 0;i < n;i++) {
            if(!visited[i]) dfs(adj,visited,i,s);
        }
        
        vector<vector<int>>adj1(n);
        for(int i = 0;i < n;i++) {
            visited[i] = 0;
            for(auto it:adj[i]) {
                adj1[it].push_back(i);
            }
        }
        
        int count = 0;
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!visited[node]) {
                count++;
                dfs_rev(adj1,visited,node);
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends