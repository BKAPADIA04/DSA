class Solution {
public:

    int check(vector<int>& prices,int index,vector<vector<int>>&dp,int option) {
        if(index >= prices.size()) return 0;

        if(dp[index][option] != -1) return dp[index][option];
        
        int opt1,opt2;

        if(option == 0) {
            opt1 = 0 + check(prices,index+1,dp,0);
            opt2 = -prices[index] + check(prices,index+1,dp,1);
        }

        if(option == 1) {
            opt1 = 0 + check(prices,index+1,dp,1);
            opt2 = prices[index] + check(prices,index+2,dp,0);
        }
        return dp[index][option] = max(opt1,opt2);
    }

    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return check(prices,0,dp,0);
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int index = n-1; index >= 0;index--) {
            for(int option = 0;option <= 1;option++) {
                int profit;
                if (option == 0) { // We can buy the stock
                profit = max(0 + dp[index + 1][0], -prices[index] + dp[index + 1][1]);
            }

            if (option == 1) { // We can sell the stock
                profit = max(0 + dp[index + 1][1], prices[index] + dp[index + 2][0]);
            }

            // Store the computed profit in the DP array
            dp[index][option] = profit;
            }
        }
    return dp[0][0];
    }
};