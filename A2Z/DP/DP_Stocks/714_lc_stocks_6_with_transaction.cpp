class Solution {
public:
    
    int check(vector<int>& prices,int index,vector<vector<int>>&dp,int option,int fee) {
        if(index >= prices.size()) return 0;

        if(dp[index][option] != -1) return dp[index][option];
        
        int opt1,opt2;

        if(option == 0) {
            opt1 = 0 + check(prices,index+1,dp,0,fee);
            opt2 = -prices[index] + check(prices,index+1,dp,1,fee);
        }

        if(option == 1) {
            opt1 = 0 + check(prices,index+1,dp,1,fee);
            opt2 = prices[index] + check(prices,index+1,dp,0,fee) - fee;
        }
        return dp[index][option] = max(opt1,opt2);
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return check(prices,0,dp,0,fee);
    }
};