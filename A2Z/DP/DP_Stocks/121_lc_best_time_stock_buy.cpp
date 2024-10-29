class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<int>dp(n,0); 
        int answer = 0;
        int maxi = prices[n-1];
        for(int i = n - 2; i >= 0;i--) {
            answer = max(answer,maxi - prices[i]);
            // dp[i] = max(dp[i+1],maxi - prices[i]);
            maxi = max(maxi,prices[i]);
        }
        // return dp[0];
        return answer;
    }
};