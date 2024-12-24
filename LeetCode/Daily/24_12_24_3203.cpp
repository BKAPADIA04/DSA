class Solution {
public:

    int bfs(map<int,vector<int>> edges,int i) {
        queue<pair<int,int>>q;
        set<int>visited;
        q.push({i,0}); int ans = 0; int src = i;
        visited.insert(i);
        while(!q.empty()) {
            src = q.front().first;
            int count = q.front().second;
            q.pop();
            ans = max(ans,count);
            vector<int>child = edges[src];
            for(int ch:child) {
                if(visited.find(ch) == visited.end()) {
                    visited.insert(ch);
                    q.push({ch,count+1});
                }
            }
        }
        // cout << "SRC : "<< src << endl;

        visited.clear(); ans = 0;
        q.push({src,0});
        visited.insert(src);

        while(!q.empty()) {
            src = q.front().first;
            int count = q.front().second;
            q.pop();
            ans = max(ans,count);
            vector<int>child = edges[src];
            for(int ch:child) {
                if(visited.find(ch) == visited.end()) {
                    visited.insert(ch);
                    q.push({ch,count+1});
                }
            }
        }
        return ans;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // return edges1.size();
        // return edges1[0][1];
        map<int,vector<int>> adj1; map<int,vector<int>> adj2;
        for(int i = 0;i < edges1.size();i++) {
            int u = edges1[i][0];
            int v = edges1[i][1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(int i = 0;i < edges2.size();i++) {
            int u = edges2[i][0];
            int v = edges2[i][1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int d1 = bfs(adj1,0);
        int d2 = bfs(adj2,0);
        int count = ceil(d1/2.0) + ceil(d2/2.0) + 1;
        cout << d1 << " " << d2 << " " << count << endl;
        return max(d1,max(d2,count));
    }
};
