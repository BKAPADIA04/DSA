//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        
        // BFS
        // vector<int>visited(adj.size(),0);
        // vector<int>answer(adj.size(),-1);
        // queue<pair<int,int>>q;
        // q.push({src,0});
        // visited[src] = 1;
        // while(!q.empty()) {
        //     int top = q.front().first;
        //     int dist = q.front().second;
        //     q.pop();
        //     answer[top] = dist;
            
        //     for(int ch:adj[top]) {
        //         if(visited[ch] == 0) {
        //             visited[ch] = 1;
        //             q.push({ch,dist+1});
        //         }
        //     }
        // }
        // return answer;
        
        // or
        vector<int>answer(adj.size(),-1);
        vector<int>distance(adj.size(),INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        distance[src] = 0;
        while(!q.empty()) {
            int top = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(int ch:adj[top]) {
                if(1 + dist < distance[ch]) {
                    distance[ch] = 1 + dist;
                    q.push({ch,distance[ch]});
                }
            }
        }
        
        for(int i = 0;i < adj.size();i++) {
            if(distance[i] != INT_MAX) answer[i] = distance[i];
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
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends