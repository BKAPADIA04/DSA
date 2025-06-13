class Solution {
public:

    int k;
    vector<vector<int>>s;
    vector<vector<int>>t;

    vector<vector<int>>dp;

    int check(int index, int node) {
        if(index >= k) return 0;

        if(dp[index][node] != -1) return dp[index][node];
        
        int ans = s[index][node] + check(index + 1, node);
        for(int i = 0;i < t[node].size();i++) {
            ans = max(ans, t[node][i] + check(index + 1,i));
        }
        return dp[index][node] = ans;
    }
    
    int maxScore(int n, int k_, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        k = k_;
        s = stayScore;
        t = travelScore;
        int ans = 0;
        dp = vector<vector<int>>(k + 1,vector<int>(n,-1));
        for(int i = 0;i < n;i++) {
            ans = max(ans,check(0,i));
        }
        return ans;
    }
};
