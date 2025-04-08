#define ll long long
class Solution {
public:

    void print(vector<ll>v) {
        for(auto it:v) cout << it << " ";
        cout << endl;
    }

    vector<ll>dijkstra(vector<vector<pair<int,ll>>>&adj, int &src,int &n) {
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        vector<ll>distance(n,LONG_MAX);
        distance[src] = 0;

        pq.push({0ll, src});
        while(!pq.empty()) {
            ll dist = pq.top().first; int node = pq.top().second; pq.pop();
            if (dist > distance[node]) continue;

            for(auto it:adj[node]) {
                int child = it.first;
                ll d = it.second;

                if(distance[node] + d < distance[child]) {
                    distance[child] = distance[node] + d;
                    pq.push({distance[child], child});
                }
            }
        }

        // for(int i = 0;i < n;i++) {
        //     if(distance[i] == LONG_MAX) distance[i] = -1;
        // }

        return distance;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,ll>>>adj(n),adj1(n);
        for(int i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],(ll)edges[i][2]});
            adj1[edges[i][1]].push_back({edges[i][0],(ll)edges[i][2]});
        }
        vector<ll>distance_src1 = dijkstra(adj,src1,n);
        vector<ll>distance_src2 = dijkstra(adj,src2,n);
        vector<ll>distance_dest = dijkstra(adj1,dest,n);

        // print(distance_src1);
        // print(distance_src2);
        // print(distance_dest);

        ll mini = LONG_MAX;
        for(int i = 0;i < n;i++) {
            ll dist1 = distance_src1[i]; ll dist2 = distance_src2[i]; ll dist3 = distance_dest[i];
            if(dist1 == LONG_MAX || dist2 == LONG_MAX || dist3 == LONG_MAX) continue;

            mini = min(mini,dist1 + dist2 + dist3);
        }
        return mini == LONG_MAX ? -1 : mini;
    }
};
