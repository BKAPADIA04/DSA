#define ll long long
class Solution {
public:

    vector<int>indegree;
    vector<vector<int>>adj;

    ll check(vector<int>&values, vector<vector<int>>&edges, int node,int parent) {
        if(indegree[node] == 1 && node != 0) {
            return values[node];
        }

        ll mini = LLONG_MAX;
        ll childSum = 0ll;
        for(auto it : adj[node]) {
            if(it == parent) continue;
            ll temp = check(values,edges,it,node);
            childSum += temp;
        }
        mini = min(childSum,(ll)values[node]);
        return mini;
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        indegree = vector<int>(n,0);
        adj = vector<vector<int>>(n);
        for(int i = 0;i < edges.size();i++) {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        ll sum = accumulate(values.begin(),values.end(),0ll);
        ll res = check(values,edges,0,-1);
        return sum - res;
    }
};
