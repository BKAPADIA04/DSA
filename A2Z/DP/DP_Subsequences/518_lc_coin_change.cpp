class Solution {
public:

    int check(int amount,vector<int>& coins,int index,vector<vector<int>>&dp) {
        if (index == 0) {
            // Check if the target sum is divisible by the first element
            return (amount % coins[0] == 0);
        }

        if(dp[index][amount] != -1) return dp[index][amount];
        int notTaken = check(amount,coins,index-1,dp);

        int taken = 0;
        if(amount >= coins[index]) {
            taken = check(amount - coins[index],coins,index,dp);
        }

        // dp[index][amount] = notTaken + taken;
        return dp[index][amount] = notTaken + taken;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return check(amount,coins,coins.size()-1,dp);
    }
};