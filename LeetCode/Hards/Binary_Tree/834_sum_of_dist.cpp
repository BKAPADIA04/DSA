class Solution {
public:

    vector<int>answer;
    vector<int>count;

    void dfs1(vector<vector<int>>&adj, int node, int parent) {
        for(auto child:adj[node]) {
            if(child == parent) continue;
            dfs1(adj,child,node);
            count[node] += count[child];
            answer[node] += answer[child] + count[child];
        }
    }

    void dfs2(vector<vector<int>>&adj, int node, int parent) {
        int n = adj.size();
        for(auto child:adj[node]) {
            if(child == parent) continue;
            answer[child] = answer[node] - count[child] + (n - count[child]);
            dfs2(adj,child,node);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        } 
        answer.resize(n,0);
        count.resize(n,1);

        dfs1(adj,0,-1);
        dfs2(adj,0,-1);
        return answer;
    }
};
