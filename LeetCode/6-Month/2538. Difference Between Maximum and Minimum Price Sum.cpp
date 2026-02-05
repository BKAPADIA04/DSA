#define ll long long
class Solution {
public:

    vector<ll>subTreeSum;
    vector<vector<int>>adj;
    ll answer;

    ll dfs0(ll node, ll parent, vector<int>& price) {
        ll maxPath = 0ll;
        for(auto it : adj[node]) {
            if(it == parent) continue;
            maxPath = max(maxPath, dfs0(it, node, price));
        }

        return subTreeSum[node] = maxPath + (ll)price[node];
    } 

    void dfs(ll node, ll parent, ll parentContribution, vector<int>& price) {
        ll maxChild = -1;
        ll maxChild1 = 0ll; ll maxChild2 = 0ll;

        for(auto it : adj[node]) {
            if(it == parent) continue;
            if(subTreeSum[it] > maxChild1) {
                maxChild2 = maxChild1;
                maxChild = it;
                maxChild1 = subTreeSum[it];
            }
            else if(subTreeSum[it] > maxChild2) {
                maxChild2 = subTreeSum[it];
            }
        }

        ll path1 = maxChild1;
        ll path2 = parentContribution;
        answer = max(answer, max(path1, path2));

        for(auto it : adj[node]) {
            if(it == parent) continue;
            if(maxChild == it) dfs(it, node, (ll)price[node] + max(maxChild2, parentContribution), price);
            else dfs(it, node, (ll)price[node] + max(maxChild1, parentContribution), price);
        }
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        adj = vector<vector<int>>(n);
        subTreeSum = vector<ll>(n,0ll);
        for(auto it : edges) {
            adj[it[0]].push_back({it[1]});
            adj[it[1]].push_back({it[0]});
        }

        ll maxPathSum = dfs0(0, -1, price);
        answer = 0ll;
        dfs(0,-1,0,price);

        return answer;
    }
};
