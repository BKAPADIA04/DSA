class Solution {
public:

    bool check(vector<vector<int>>& graph,vector<int>&visited,vector<int>&color,int source) {
        int n = graph.size();
        queue<int>q;
        q.push(source);
        visited[source] = 1;
        color[source] = 1;
        while(!q.empty()) {
            int src = q.front(); q.pop(); 
            vector<int>child = graph[src];
            for(int ch:child) {
                if(color[ch] == color[src]) return false;
                if(visited[ch] == 0) {
                    visited[ch] = 1;
                    color[ch] = 1 - color[src];
                    q.push(ch);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,0);
        vector<int>color(n,-1);
        bool ans = true;
        for(int i = 0; i < n;i++) {
            if(visited[i] == 0) {
                ans = ans && check(graph,visited,color,i);
            }
        }
        return ans;
    }
};