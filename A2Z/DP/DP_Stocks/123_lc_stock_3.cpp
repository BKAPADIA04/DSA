class Solution {
public:

    int answer(vector<int>& prices,int index,int option,int count,vector<vector<vector<int>>>&dp) {
        if(index >= prices.size()) return 0;
        if(count == 0) return 0;
        if(dp[index][option][count] != -1) return dp[index][option][count];

        int opt1,opt2;

        if(option == 0) {
            opt1 = 0 + answer(prices,index+1,0,count,dp);
            opt2 = -prices[index] + answer(prices,index+1,1,count,dp);
        }
        
        if(option == 1) {
            opt1 = 0 + answer(prices,index+1,1,count,dp);
            opt2 = +prices[index] + answer(prices,index+1,0,count-1,dp);
        }

        return dp[index][option][count] = max(opt1,opt2);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return answer(prices,0,0,2,dp);
    }
};