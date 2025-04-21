class Solution {
public:

    vector<int>preSum;
    vector<vector<int>>dp;
    int n;

    int check(vector<int>&stoneValue, int i, int j) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxi = 0;

        for(int k = i + 1;k <= j;k++) {
            int leftPart = preSum[k] - preSum[i];
            int rightPart = preSum[j + 1] - preSum[k];
            if(leftPart > rightPart) {
                maxi = max(maxi, rightPart + check(stoneValue, k , j));
            }
            else if(leftPart < rightPart) {
                maxi = max(maxi, leftPart + check(stoneValue, i , k - 1));
            }
            else {
                int temp1 = max(maxi, rightPart + check(stoneValue, i, k - 1));
                int temp2 = max(maxi, leftPart + check(stoneValue, k , j));
                maxi = max(maxi,max(temp1,temp2));
            }
        }
        return dp[i][j] = maxi;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        preSum = vector<int>(n + 1,0);
        dp = vector<vector<int>>(n + 1,vector<int>(n + 1,-1));
        for(int i = 1;i <= n;i++) {
            preSum[i] = preSum[i - 1] + stoneValue[i - 1];
        }

        return check(stoneValue, 0, n - 1);
    }
};
