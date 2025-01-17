class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i < edges.size();i++) {
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>out(n); vector<int>visited(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int maxi = 0;
        while(!pq.empty()) {
            int wt = pq.top().first; int node = pq.top().second; pq.pop();
            if(visited[node]) continue;
            visited[node] = 1;
            maxi = max(maxi,wt);

            for(auto it:adj[node]) {
                if(!visited[it.first] && out[it.first] <= threshold) {
                    // out[it]++;
                    pq.push({it.second,it.first});
                }
            }
        }
        for(int i = 0;i < n;i++) {
            if(visited[i] == 0) return -1;
        }
        return maxi;
    }
};
