class Solution {
public:

    void print(vector<vector<int>>v) {
        for(auto it:v) {
            for(auto it1:it) cout << it1 << " ";
            cout << endl;
        }
    }
    
    int check(vector<vector<int>>&coins,vector<vector<vector<int>>>&dp,int i,int j,int k) {
        // cout << i << " " << j << " " << k << endl;
        if(i < 0 || i >= coins.size() || j < 0 || j >= coins[0].size()) return INT_MIN;
        if(i == (coins.size()-1) && j == (coins[0].size()-1)) {
            if(coins[i][j] >= 0) {
                return coins[i][j];
            }
            else {
                if(k > 0) {
                    return 0;
                }
                else {
                    return coins[i][j];
                }
            }
        }
        
        if(dp[i][j][k] != -1e9) return dp[i][j][k];
        
        int down = INT_MIN; int right = INT_MIN;    
        if(coins[i][j] >= 0) {
            // cout << i << " " << j << " " << sum << endl;
            down = check(coins,dp,i+1,j,k);
            right = check(coins,dp,i,j+1,k);
            
            if(down != INT_MIN) down += coins[i][j];
            if(right != INT_MIN) right += coins[i][j];

            dp[i][j][k] = max(down,right);
        }
        else {
            int maxi = INT_MIN;
            if(k > 0) {
                int neutralizeDown = check(coins,dp,i+1,j,k-1);
                int neutralizeRight = check(coins,dp,i,j+1,k-1);
                maxi = max(maxi,max(neutralizeDown,neutralizeRight));
            }

            int noNeutralizeRight = check(coins, dp, i, j + 1, k);
            int noNeutralizeDown = check(coins, dp, i + 1, j, k);

            if (noNeutralizeRight != INT_MIN) noNeutralizeRight += coins[i][j];
            if (noNeutralizeDown != INT_MIN) noNeutralizeDown += coins[i][j];

            maxi = max(maxi,max(noNeutralizeRight,noNeutralizeDown));
            dp[i][j][k] = maxi;
        }
        return dp[i][j][k];
    }
    
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,-1e9)));
        int answer = check(coins,dp,0,0,2);
        // cout << dp[m-1][n-1][0] << " " << dp[m-1][n-1][1] << " " << dp[m-1][n-1][2] << endl;
        // print(dp);
        return answer;
    }
};
