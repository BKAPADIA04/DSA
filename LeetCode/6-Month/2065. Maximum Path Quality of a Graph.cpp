#define ll long long
class Solution {
public:

    vector<vector<pair<int,int>>>adj;

    void check(int node, int time, int maxTime, unordered_map<int,int>&st,vector<int>& values, ll &answer, ll score) {

        if(st.find(node) == st.end()) score += values[node];
        st[node] += 1;

        if(node == 0) {
            answer = max(answer,score);
        }

        for(auto it : adj[node]) {
            int v = it.first; int t = it.second;
            if(time + t > maxTime) continue;
            check(v, time + t, maxTime,st,values,answer,score); 
        }

        st[node] -= 1;
        if(st[node] == 0) st.erase(node);
    } 

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int m = edges.size();
        int n = values.size();
        adj = vector<vector<pair<int,int>>>(n);

        for(auto it:edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        unordered_map<int,int>st;
        ll answer = 0ll;
        check(0,0,maxTime,st,values,answer,0);
        return answer;
    }
};
