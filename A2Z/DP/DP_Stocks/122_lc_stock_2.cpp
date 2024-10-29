class Solution {
public:
    int answer(vector<int>& prices,int index,int option,vector<vector<int>>&dp) {
        if(index >= prices.size()) {
            return 0;
        }

        if(dp[index][option] != -1) return dp[index][option];
        int opt1,opt2;
        if(option == 0) {
            opt1 = 0 + answer(prices,index+1,0,dp);
            opt2 = -prices[index] + answer(prices,index + 1,1,dp);
        }

        if(option == 1) {
            opt1 = 0 + answer(prices,index+1,1,dp);
            opt2 = prices[index] + answer(prices,index+1,0,dp);
        }
        return dp[index][option] = max(opt1,opt2);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return answer(prices,0,0,dp);

        // for(int index = 1;index <= prices.size();index++) {
        //     for(int option = 1;option <= 2;option++) {
        //         dp[index][option] = max(dp[index-1][option],prices[index-1] + dp[index-1][option-1]);
        //     }
        // }
        // return max(dp[prices.size()][1],dp[prices.size()][2]);
    }
};