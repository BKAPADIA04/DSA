#define ll long long
class Solution {
public:

    vector<vector<ll>>adj;
    vector<ll>primeMul;

    void primeMulti() {
        primeMul = vector<ll>(1e5+1,0);
        for (int i = 1; i <= 1e5; i++) primeMul[i] = i;
        for (int i = 2; i * i <= 1e5; i++) {
            long long sq = 1LL * i * i;
            for (int j = sq; j <= 1e5; j += sq)
                while (primeMul[j] % sq == 0) primeMul[j] /= sq;
        }
    }

    void check(ll &answer, int node, int parent,unordered_map<ll,ll>&freqMap,vector<ll>&arr) {
        if(parent != -1) answer = answer + freqMap[arr[node]];
        freqMap[arr[node]]++;   
        for(auto it:adj[node]) {
            if(it == parent) continue;
            check(answer, it, node, freqMap, arr);
        }
        freqMap[arr[node]]--;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        adj = vector<vector<ll>>(n);
        for(ll i = 0;i < edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        primeMulti();
        vector<ll>arr(n);
        for(ll i = 0;i < n;i++) arr[i] = primeMul[nums[i]];

        unordered_map<ll,ll>freqMap;
        ll answer = 0ll;
        check(answer, 0, -1, freqMap, arr);
        return answer;
    }
};
