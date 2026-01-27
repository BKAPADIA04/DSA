#define ll long long
class Solution {
public:

    vector<vector<pair<ll,ll>>>adj1,adj2;
    void print(vector<ll>dis) {
        for(auto it : dis) cout << it << " ";
        cout << endl;
    }

    ll check(int n) {
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>pq;
        pq.push({0,0,0});
        vector<ll>distance(n,INT_MAX);
        distance[0] = 0;

        while(!pq.empty()) {
            ll dist = pq.top()[0];
            ll node = pq.top()[1];
            ll type = pq.top()[2];
            pq.pop();

            if(node == (n-1)) return dist;

            for(auto it : adj1[node]) {
                ll chNode = it.first;
                ll wt = it.second;

                if(dist + wt < distance[chNode]) {
                    distance[chNode] = dist + wt;
                    pq.push({distance[chNode],chNode, type});
                }
            }

            // if(type == 0) {
            for(auto it : adj2[node]) {
                ll chNode = it.first;
                ll wt = it.second;
                // if(node == chNode) continue;

                if(dist + wt < distance[chNode]) {
                    distance[chNode] = dist + wt;
                    pq.push({distance[chNode],chNode, 1});
                }
            }
            // }
        }

        return -1;
    }

    int minCost(int n, vector<vector<int>>& edges) {
        adj1 = vector<vector<pair<ll,ll>>>(n);
        adj2 = vector<vector<pair<ll,ll>>>(n);

        for(int i = 0;i < edges.size();i++) {
            adj1[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj2[edges[i][1]].push_back({edges[i][0],(ll)2 * edges[i][2]});
        }



        return check(n);
    }
};
