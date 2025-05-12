class Solution {
public:

    vector<vector<pair<int,int>>>adj;
    unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;

    int check(int node, int k, int sum, int t) {
        if(k == 0) {
            return sum < t ? sum : -1;
        }

        if(dp.find(node) != dp.end() && dp[node].find(k) != dp[node].end() && dp[node][k].find(sum) != dp[node][k].end()) return dp[node][k][sum];

        int maxSum = -1;
        for(auto it : adj[node]) {
            int v = it.first; int wt = it.second;
            int newSum = sum + wt;
            if(newSum >= t) continue;
            int res = check(v,k-1,newSum,t);
            if(res != -1) {
                maxSum = max(maxSum,res);
            }
        }

        return dp[node][k][sum] = maxSum;
    }

    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        adj = vector<vector<pair<int,int>>>(n);
        for(auto it : edges) {
            int u = it[0]; int v = it[1]; int wt = it[2];
            adj[u].push_back({v,wt});
        }

        int ans = -1;
        for(int i = 0;i < n;i++) {
            ans = max(ans,check(i,k,0,t));
        }

        return ans;
    }
};
