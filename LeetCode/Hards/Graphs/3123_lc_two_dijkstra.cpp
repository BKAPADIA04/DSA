#define ll long long
class Solution {
public:

    void print(vector<ll>v) {
        for(auto it:v) cout << it << " ";
        cout << endl;
    }

    vector <ll> shortest_dijk(int n,vector<vector<pair<ll,ll>>>&adj,ll start) {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vector<ll>dist(n,LLONG_MAX);
        dist[start] = 0;
        pq.push({0,start});
        while(!pq.empty()) {
            ll node = pq.top().second;
            ll distance = pq.top().first;
            pq.pop();

            for(auto it:adj[node]) {
                ll child = it.first;
                ll wt = it.second;

                if(dist[node] != LLONG_MAX && dist[node] + wt < dist[child]) {
                    dist[child] = dist[node] + wt;
                    pq.push({dist[child],child});
                }
            }
        }
        return dist;
    }

    void dfs(int n,vector<vector<pair<int,int>>>&adj,vector<int>&visited,vector<int>&tempo,int index,int sum,int &short_dist,set<pair<int,int>>&s) {
        if(index == (n-1)) {
            if(sum == short_dist) {
                // print_vector(tempo);
                for(int i = 1;i < tempo.size();i++) s.insert({tempo[i-1],tempo[i]});
            }
            // else if(sum < short_dist) {
            //     for(int i = 0;i < answer.size();i++) answer[i] = false;
            //     short_dist = sum;
            //     for(int i = 0;i < tempo.size();i++) answer[tempo[i]] = true;
            // }
            return;
        }

        for(auto it:adj[index]) {
            int node = it.first;
            int dist = it.second;

            if(!visited[node]) {
                visited[node] = 1; 
                tempo.push_back(node);
                dfs(n,adj,visited,tempo,node,sum + dist,short_dist,s);
                visited[node] = 0;
                tempo.pop_back();
            }
        }

    }

    // vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
    //     vector<vector<pair<int,int>>>adj(n);
    //     for(int i = 0;i < edges.size();i++) {
    //         adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    //         adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    //     }
        
    //     int short_dist = shortest_dijk(n,adj);
    //     vector<int>visited(n),tempo = {0};
    //     visited[0] = 1;
    //     set<pair<int,int>>s;
    //     // int short_dist = INT_MAX;
    //     dfs(n,adj,visited,tempo,0,0,short_dist,s);
        
    //     // print(s);
    //     vector<bool>edge_answer(edges.size());
    //     for(int i = 0;i < edges.size();i++) {
    //         int node1 = edges[i][0]; int node2 = edges[i][1];
    //         auto it1 = s.find({node1,node2});
    //         auto it2 = s.find({node2,node1});
    //         if(it1 != s.end() || it2 != s.end()) {
    //             edge_answer[i] = true;
    //         }
    //     }

    //     return edge_answer;
    // }


    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<ll,ll>>>adj(n);
        for(ll i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        vector<ll>d1 = shortest_dijk(n,adj,0);
        vector<ll>d2 = shortest_dijk(n,adj,n-1);

        // print(d1); print(d2);

        ll short_dist = d1[n-1];
        vector<bool>edge_answer(edges.size());
        for(ll i = 0;i < edges.size();i++) {
            ll u = edges[i][0]; ll v = edges[i][1];
            if(d1[u] != LLONG_MAX && d2[v] != LLONG_MAX && edges[i][2] + d1[u] + d2[v] == short_dist) edge_answer[i] = true;

            u = edges[i][1]; v = edges[i][0];
            if(d1[u] != LLONG_MAX && d2[v] != LLONG_MAX && edges[i][2] + d1[u] + d2[v] == short_dist) edge_answer[i] = true;
        }
        return edge_answer;
    }
};
