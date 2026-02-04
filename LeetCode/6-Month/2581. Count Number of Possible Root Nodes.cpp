class Solution {
public:

    vector<vector<int>>adj;
    int n;
    map<pair<int,int>, int>mp;
    int answer;

    void dfs0(int node, int parent, int &ans) {
        for(auto it : adj[node]) {
            if(it == parent) continue;
            if(mp.find({node, it}) != mp.end()) {
                ans += 1;
            }
            dfs0(it, node, ans);
        }
    }


    void dfs(int node, int parent, int ans, int k) {
        if(ans >= k) answer++;
        for(auto it : adj[node]) {
            if(it == parent) continue;
            int newAns = ans;
            if(mp.find({node, it}) != mp.end()) {
                newAns -= 1;
            }
            if(mp.find({it, node}) != mp.end()) {
                newAns += 1;
            }
            dfs(it, node, newAns, k);
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        n = edges.size() + 1;
        adj = vector<vector<int>>(n);

        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(auto it : guesses) {
            mp[{it[0], it[1]}] = 1;
        }

        int ans = 0;
        dfs0(0,-1,ans);

        answer = 0;
        dfs(0,-1,ans,k);
        return answer;
    }
};
