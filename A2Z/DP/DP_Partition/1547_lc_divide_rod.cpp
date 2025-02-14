class Solution {
public:

    int check(vector<int>& cuts,vector<vector<int>>&dp,int i,int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k = i;k <= j;k++) {
            int tempo = (cuts[j+1] - cuts[i-1]) + check(cuts,dp,i,k-1) + check(cuts,dp,k+1,j);
            mini = min(mini,tempo);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        // int i = 1; int j = cuts.size() - 2;
        sort(cuts.begin(),cuts.end());
        // vector<vector<int>>dp(c+1,vector<int>(c+1,-1));

        // return check(cuts,dp,i,c);
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));

        for(int i = c + 1;i >= 1;i--) {
            for(int j = 1;j <= c;j++) {
                if(i > j) continue;
                int mini = INT_MAX;
                for(int k = i;k <= j;k++) {
                    int tempo = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini,tempo);
                }

                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};