#define ll long long
class Solution {
public:

    vector<vector<int>>adj;
    vector<int>c;
    vector<ll>maximum;

    long long preCompute(int node, int parent) {
        long long maxi = 0;
        for(auto it : adj[node]) {
            if(it == parent) continue;
            ll temp = preCompute(it,node);
            maxi = max(maxi,temp);
        }
        maximum[node] = maxi;
        return maxi + c[node];
    }


    ll check(int node, int parent, int &ans) {
        ll pathSum = c[node];
        for(auto it : adj[node]) {
            if(it == parent) continue;
            ll temp = check(it,node,ans);
            if(temp != maximum[node]) {
                ans += 1;
            }
        }
        return maximum[node] + pathSum;
    }


    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        adj = vector<vector<int>>(n);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        c = cost;
        maximum = vector<ll>(n,0);
        preCompute(0,-1);
        // for(auto it : maximum) cout << it << " ";
        int ans = 0;
        check(0,-1,ans);
        return ans;
    }
};
