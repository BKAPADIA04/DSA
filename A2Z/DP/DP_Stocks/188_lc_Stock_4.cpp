class Solution {
public:

    int answer(int k, vector<int>& prices,int index,vector<vector<vector<int>>>&dp,int option) {
        if(index == prices.size() || k < 0) {
            return 0;
        }

        if(dp[index][option][k] != -1) return dp[index][option][k];

        int opt1,opt2;

        if(option == 0) {
            opt1 = 0 + answer(k,prices,index+1,dp,0);
            opt2 = -prices[index] + answer(k,prices,index+1,dp,1);
        }

        if(option == 1) {
            opt1 = 0 + answer(k,prices,index+1,dp,1);
            opt2 = prices[index] + answer(k-1,prices,index+1,dp,0);
        }

        return dp[index][option][k] = max(opt1,opt2);
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k,-1)));

        return answer(k-1,prices,0,dp,0);
    }
};