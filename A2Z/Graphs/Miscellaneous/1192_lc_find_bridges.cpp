class Solution {
public:

    void dfs(vector<vector<int>>&ans,vector<vector<int>>&adj,vector<int>&visited, vector<int>&in,vector<int>&low,int i,int par, int &time) {
        visited[i] = 1; 
        in[i] = time; low[i] = time;
        time = time + 1;

        for(auto it:adj[i]) {
            if(it == par) continue;
            if(!visited[it]) {
                dfs(ans,adj,visited,in,low,it,i,time);
                low[i] = min(low[i],low[it]);

                if(low[it] > in[i]) {
                    ans.push_back({it,i});
                }
            }
            else {
                low[i] = min(low[i],low[it]);
            }
        }
    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i = 0;i < connections.size();i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int>visited(n),in(n),low(n);
        vector<vector<int>>ans; int time = 1;
        dfs(ans,adj,visited,in,low,0,-1,time);

        return ans;
    }
};