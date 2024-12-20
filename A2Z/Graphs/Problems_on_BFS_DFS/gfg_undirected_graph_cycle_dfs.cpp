//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    void print(vector<int>visited) {
        for(auto it : visited) cout << it << " ";
        cout << endl;
    }
    
    bool check(vector<vector<int>>& adj,vector<int>&visited,int i) {
        queue<pair<int,int>>q;
        q.push({i,-1});
        visited[i] = -1;
        while(!q.empty()) {
            int source = q.front().first;
            int parent = q.front().second;
            vector<int>dest = adj[source];
            q.pop();
            // if(visited[source] != -1 || visited[source] != -2) return false;
            for(int child:dest) {
                if(child != parent) {
                    if(visited[child] != -2) return true;
                    q.push({child,source});
                    visited[child] = source;
                }
            }
        }
        // print(visited);
        return false;
    }
    
    
    // bool isCycle(vector<vector<int>>& adj) {
    //     // Code here
    //     int n = adj.size();
    //     vector<int>visited(n,-2);
    //     for(int i = 0;i < n;i++) {
    //         if(visited[i] == -2) {
    //             // visited[i] = 1;
    //             bool ans = check(adj,visited,i);
    //             if(ans == true) return true;
    //         }
    //     }
    //     return false;
    // }
    
    void dfs(vector<vector<int>>& adj,vector<int>&visited,int src,int par,bool &ans) {
        visited[src] = par;
        vector<int>dest = adj[src];
        for(int child:dest) {
            if(child != par) {
                if(visited[child] != -2) { ans = true; return;}
                dfs(adj,visited,child,src,ans);
            }
        }
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>visited(n,-2);
        bool answer = false;
        for(int i = 0;i < n;i++) {
            if(visited[i] == -2) {
                // visited[i] = 1;
                dfs(adj,visited,i,-1,answer);
                if(answer == true) return true;
            }
        }
        return answer;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends