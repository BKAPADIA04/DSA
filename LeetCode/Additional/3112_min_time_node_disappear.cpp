class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {

        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        vector<int>distance(n,-1);
        distance[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(time > distance[node]) continue;

            for(auto it : adj[node]) {
                int ch = it.first;
                int t = it.second;

                if(ch == node) continue;

                if(time + t < disappear[ch]) {
                    if(distance[ch] == -1) {
                        distance[ch] = distance[node] + t;
                        pq.push({distance[ch],ch});
                    }
                    else if(distance[node] + t < distance[ch]) {
                        distance[ch] = distance[node] + t;
                        pq.push({distance[ch],ch});
                    }
                }
            }
        }
        // for(int i = 0;i < n;i++) {
        //     if(distance[i] == INT_MAX) distance[i] = -1;
        // }
        return distance;
    }
};
