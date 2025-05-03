class Solution {
public:

    void check(vector<int>&visited, vector<vector<int>>&adj, vector<int>&answer, int node) {
        queue<int>q;
        q.push(node); // node
        // visited[0] = 1;
        // answer[0] = 1;
        while(!q.empty()) {
            int node = q.front(); 
            q.pop();
            
            unordered_map<int,int>umap;
            for(auto it : adj[node]) {
                if(visited[it]) {
                    umap[answer[it]]++;
                    continue;
                }
                visited[it] = 1; q.push(it); 
            }
            for(int i = 1;i <= 4;i++) {
                if(umap.find(i) != umap.end()) continue;
                answer[node] = i; 
                break;
            }
        }
    }

    void dfs(vector<int>&visited, vector<vector<int>>&adj, vector<int>&answer, int node) {
        visited[node] = 1;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs(visited, adj, answer, it);
            }
        }
        // answer[node] = 1;
        unordered_map<int,int>umap;
        for(auto it : adj[node]) {
            umap[answer[it]]++;
        }
        for(int i = 1;i <= 4;i++) {
            if(umap.find(i) != umap.end()) continue;
            answer[node] = i; 
            break;
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n);
        for(auto it : paths) {
            int u = it[0]; int v = it[1]; adj[u - 1].push_back(v - 1); adj[v - 1].push_back(u - 1); 
        }

        vector<int>answer(n,-1);
        vector<int>visited(n,0);
        // for(int i = 0;i < n;i++) {
        //     if(!visited[i]) check(visited, adj, answer, i);
        // }
        for(int i = 0;i < n;i++) {
            if(!visited[i]) dfs(visited, adj, answer, i);
        }
        return answer;
    }
};

/*class Solution {
public:
    bool possible(vector<vector<int>>& adj, vector<int>& ans, int n, int node, int i) {
        for (auto it : adj[node]) {
            if (ans[it - 1] == i) return 0;
        }
        return 1;
    }
    bool solve(vector<vector<int>>& adj, vector<int>& ans, int n, int m, int node) {
        if (node == n + 1) {
            return 1;
        }
        for (int i = 1; i <= m; i++) {
            if (possible(adj, ans, n, node, i) == 1) {
                ans[node - 1] = i;
                if (solve(adj, ans, n, m, node + 1) == 1) return 1;
                ans[node - 1] = 0;
            }
        }
        return 0;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < paths.size(); i++) {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> ans(n, 0);
        solve(adj, ans, n, 4, 1);
        return ans;
    }
};*/
