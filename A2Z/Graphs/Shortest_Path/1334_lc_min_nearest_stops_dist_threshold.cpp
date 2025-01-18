class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(int i = 0;i < edges.size();i++) {
            int u = edges[i][0]; int v = edges[i][1]; int wt = edges[i][2];
            adj[u][v] = wt; adj[v][u] = wt;
        }

        for(int i = 0;i < n;i++) {
            adj[i][i] = 0;
        }

        for(int k = 0;k < n;k++) {
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) {
                    adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
                }
            }
        }

        int index = -1; int final_count = n;
        for(int i = 0;i < n;i++) {
            int count = 0;
            for(int j = 0;j < n;j++) {
                if(adj[i][j] <= threshold) count++;
            }
            if(count <= final_count) { final_count = count; index = i;}
        }
        return index;
    }
};