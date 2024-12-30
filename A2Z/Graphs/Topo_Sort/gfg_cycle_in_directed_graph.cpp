//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(vector<vector<int>> &adj,vector<int>&visited,vector<int>&pathVisited,int src) {
        visited[src] = 1;
        pathVisited[src] = 1;
        
        vector<int>child = adj[src];
        for(int ch:child) {
            if(!visited[ch]) {
                if(dfs(adj,visited,pathVisited,ch)) return true;
            }
            else if(pathVisited[ch]) return true;
        }
        pathVisited[src] = 0;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        
        // BFS
        // vector<int>indegree(V,0);
        // for(int i = 0;i < V;i++) {
        //     for(int ch:adj[i])  indegree[ch]++;
        // }
        
        // queue<int>q;
        // for(int i = 0;i < V;i++) {
        //     if(indegree[i] == 0) q.push(i);
        // }
        
        // int temp = V;
        // while(!q.empty()) {
        //     int top = q.front();
        //     q.pop();
        //     temp--;
        //     for(int ch:adj[top]) {
        //         indegree[ch]--;
        //         if(indegree[ch] == 0) q.push(ch);
        //     }
        // }
        // return temp != 0;
        
        // DFS
        vector<int>visited(V,0);
        vector<int>pathVisited(V,0);
        
        bool ans = true;
        for(int i = 0;i < V;i++) {
            if(visited[i] == 0) {
                if(dfs(adj,visited,pathVisited,i)) return true;
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends