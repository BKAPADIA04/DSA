class Solution {
public:

    int check(vector<int>&prices,int index,vector<int>&dp) {
        int n = prices.size();
        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        int mini = INT_MAX;
        for(int i = index + 1; i <= 2 * index + 2;i++) {
            mini = min(mini,check(prices,i,dp));
        }
        return dp[index] = mini + prices[index];
    }

    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n,-1);
        return check(prices,0,dp);
    }
};
