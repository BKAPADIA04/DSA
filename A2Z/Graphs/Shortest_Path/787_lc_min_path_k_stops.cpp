class Solution {
public:
    void print(vector<int>ans) {
        for(auto it:ans) cout << it << " ";
        cout << endl;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i < flights.size();i++) {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        pq.push({0,0,src});

        while(!pq.empty()) {
            int distance = pq.top()[1];
            int kth = pq.top()[0];
            int node = pq.top()[2];

            pq.pop();

            if(kth > k) continue;

            // if(node == dst && kth <= (k+1)) return distance;

            for(auto it:adj[node]) {
                if(distance + it.second < dist[it.first] && kth <= k) {
                    dist[it.first] = distance + it.second;
                    pq.push({kth+1,dist[it.first],it.first});
                }
            }
        }
        print(dist);
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
        
    }
};