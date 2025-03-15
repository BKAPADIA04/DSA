class Solution {
public:

    int check(vector<int>&arr,vector<vector<int>>&dp,int i,int j) {
        int n = arr.size();
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
    
        for(int k = i;k < j;k++) {
            int maxi_i = arr[i]; int maxi_j = arr[j];
            for(int tempo = i;tempo <= k;tempo++) maxi_i = max(maxi_i,arr[tempo]);
            for(int tempo = k + 1; tempo <= j;tempo++) maxi_j = max(maxi_j,arr[tempo]);

            int temp = maxi_i * maxi_j + check(arr,dp,i,k) + check(arr,dp,k+1,j);
            mini = min(mini,temp);
        }
        return dp[i][j] = mini;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n+2,-1));
        return check(arr,dp,0,n-1);
    }
};
