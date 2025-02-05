class Solution {
public:
    void print(vector<int>ans) {
        for(auto it:ans) cout << it << " " ;
        cout << endl;
    }

    void dfs(vector<vector<int>>&adj,vector<int>&visited,int node,vector<int>&ans,vector<int>&temp) {
        int check = 0;
        for(auto it:adj[node]) {
            if(!visited[it]) {
                check = 1;
                visited[it] = 1;
                temp.push_back(it);
                dfs(adj,visited,it,ans,temp);
                visited[it] = 0;
                temp.pop_back();
            }
        }
        if(check == 0) {
            if(ans.size() < temp.size()) {
                ans = temp;
            }
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int>q;
        vector<int>visited(n);
        q.push(0);
        visited[0] = 1; int node = 0;
        while(!q.empty()) {
            node = q.front();
            q.pop();

            for(auto it:adj[node]) {
                if(!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        vector<int>temp = {node};
        vector<int>ans = {};
        for(int i = 0;i < n;i++) {
            visited[i] = 0;
        }
        visited[node] = 1;
        dfs(adj,visited,node,ans,temp);

        int m = ans.size();
        if((m & 1)) {
            return {ans[m/2]};
        }
        return {ans[m/2 - 1], ans[m/2]};
    }
};

/*
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0}; 

        //build the adjList and degree array
        vector<vector<int>> adjList(n);
        vector<int> degree(n,0);

        for (auto & edge: edges){
            int src = edge[0]; 
            int dest = edge[1]; 
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
            degree[src]++;
            degree[dest]++;
        }

        //push all initial leaf nodes (degree==1) into the queue

        queue<int> leaves;
        for(int i = 0; i < n; i++){
            if(degree[i] ==1) leaves.push(i); 
        }

        //process leaves layer by layer by removing leaves iteratively
        int remainingNodes = n;
        while(remainingNodes > 2) {
            int leafCount = leaves.size(); 
            remainingNodes -= leafCount; 

            for(int i = 0; i < leafCount; i++){
                int leaf = leaves.front();
                leaves.pop(); 

                for(int neighbor : adjList[leaf]){
                    degree[neighbor]--;
                    if (degree[neighbor]== 1) leaves.push(neighbor);
                }
            }

        }

        //remaining nodes are MHT
        vector<int> res; 
        while(!leaves.empty()){
            res.push_back(leaves.front());
            leaves.pop();
        }

        return res;
    }
};
*/
