//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
#define p pair<int,int>
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        vector<int>answer(adj.size(),INT_MAX);
        // vector<int>visited(adj.size(),-1);
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,src});
        while(!pq.empty()) {
            int top = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if(answer[top] != INT_MAX) continue;
            answer[top] = dist;
            
            for(auto child:adj[top]) {
                int ch_node = child.first;
                int wt_node = child.second;
                
                pq.push({answer[top] + wt_node,ch_node});
            }
        }
        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends