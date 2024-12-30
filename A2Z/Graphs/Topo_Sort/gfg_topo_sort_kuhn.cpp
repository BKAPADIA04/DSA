//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    // void dfs(vector<vector<int>>& adj,vector<int>&visited,stack<int>&s,int i) {
    //     visited[i] = 1;
    //     vector<int>child = adj[i];
    //     for(int ch:child) {
    //         if(visited[ch] == -1) {
    //             dfs(adj,visited,s,ch);
    //         }
    //     }
    //     s.push(i);
    // }
        
    void print(vector<int>v) {
        for(auto it:v) cout << it << " ";
        cout << endl;
    }
    
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Kuhn Algorithm
        vector<int>ans;
        int n = adj.size();
        vector<int>indegree(n,0);
        for(int i = 0;i < n;i++) {
            vector<int>child = adj[i];
            for(int ch:child) indegree[ch]++;
        }
        
        
        // print(indegree);
        
        queue<int>q;
        for(int i = 0; i < indegree.size();i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            
            for(int ch:adj[top]) {
                indegree[ch]--;
                if(indegree[ch] == 0) q.push(ch);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends