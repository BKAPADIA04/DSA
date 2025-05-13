class Solution {
public:

    int check(vector<int>&coins, int amount,vector<int>&dp) {
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int ans = 1e9;
        for(int i = 0;i < coins.size();i++) {
            if(coins[i] <= amount) {
                ans = min(ans,1 + check(coins,amount - coins[i],dp));
            }
        }
        return dp[amount] = ans;
    }


    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int>dp(amount + 1,amount + 1);
        dp[0] = 0;
        for(int coin:coins) {
            for(int i = coin; i <= amount;i++) {
                dp[i] = min(dp[i],dp[i-coin] + 1);
            }
        }
        // return dp[amount] == amount + 1 ? -1 : dp[amount];
        vector<int>dp_rec(amount + 1,-1);
        int ans = check(coins,amount,dp_rec);
        // return ans == 1e9 ? -1 : ans;


        vector<int>dp_tab(amount+1,amount+1);
        dp_tab[0] = 0;
        for(int i = 1;i <= amount;i++) {
            for(int j = 0;j < coins.size();j++) {
                int temp = 1e9;
                if(coins[j] <= i) temp = 1 + dp_tab[i - coins[j]];
                dp_tab[i] = min(dp_tab[i],temp);
            }
        }
        return dp_tab[amount] == amount + 1 ? -1 : dp_tab[amount];
    }
};


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

