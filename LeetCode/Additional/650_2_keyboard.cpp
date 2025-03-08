class Solution {
public:

    int check(int n,vector<vector<int>>&dp,int curr,int paste) {
        if(curr == n) return 0;
        if(curr > n) return 10000;

        if(dp[curr][paste] != -1) return dp[curr][paste];

        int opt1 = 1 + check(n,dp,curr + paste,paste);
        int opt2 = 2 + check(n,dp,2 * curr,curr);

        return dp[curr][paste] = min(opt1,opt2);
    }


    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        int ans = check(n,dp,1,1);
        return 1 + ans;
    }
};
