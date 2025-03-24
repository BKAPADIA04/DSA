
#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll mod = 1e9 + 7;

        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i < roads.size();i++) {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
        vector<ll>distance(n,LLONG_MAX); vector<ll>paths(n,0);
        distance[0] = 0; paths[0] = 1;
        pq.push({0,0});
        while(!pq.empty()) {
            ll dist = pq.top()[0]; 
            ll node = pq.top()[1]; 
            pq.pop();

            if(dist > distance[node]) continue;
            for(auto it:adj[node]) {
                ll next_node = it.first;
                ll next_dist = it.second;

                if(dist + next_dist < distance[next_node]) {
                    distance[next_node] = dist + next_dist;
                    paths[next_node] = paths[node];
                    pq.push({distance[next_node],next_node});
                }
                else if(dist + next_dist == distance[next_node]) {
                    paths[next_node] = (paths[next_node] + paths[node]) % mod;
                }
            }
        }
        return paths[n-1];
    }
};
