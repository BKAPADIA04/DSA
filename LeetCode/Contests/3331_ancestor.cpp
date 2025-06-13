class Solution {
public:

    int n;
    vector<vector<int>>adj;
    string str;
    vector<stack<int>>st;
    vector<int>p;
    vector<vector<int>>adj1;

    void check(int node, int parent, string &s) {
        s.push_back(str[node]);
        st[str[node] - 'a'].push(node);

        for(auto it : adj[node]) {
            if(it == parent) continue;
            check(it,node,s);
        }
        
        st[str[node] - 'a'].pop();
        s.pop_back();

        if(st[str[node] - 'a'].size() > 0) {
            p[node] = st[str[node] - 'a'].top();
        }
    }

    int subTree(int node,int parent,vector<int>&dp) {
        int ans = 1;
        for(auto it : adj1[node]) {
            if(it == parent) continue;
            int temp = subTree(it,node,dp);
            ans += temp;
        }
        dp[node] = ans;
        return ans;
    }
    
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        n = parent.size();
        p = parent;
        str = s;
        adj = vector<vector<int>>(n);

        for(int i = 0;i < n;i++) {
            if(parent[i] == -1) continue;
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        st = vector<stack<int>>(26);

        string temp = "";
        check(0,-1,temp);

        adj1 = vector<vector<int>>(n);
        
        for(int i = 0;i < n;i++) {
            if(p[i] == -1) continue;
            adj1[i].push_back(p[i]);
            adj1[p[i]].push_back(i);
        }

        vector<int>dp(n,0);
        subTree(0,-1,dp);
        
        return dp;
    }
};
