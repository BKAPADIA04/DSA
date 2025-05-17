class Solution {
public:

    int n;
    vector<int>dp;

    int check(vector<int>&arr, int i, int k) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int maxi = -1;
        int ans = 0;
        for(int j = i;j < min(n,i + k);j++) {
            maxi = max(maxi, arr[j]);
            int temp = maxi * (j - i + 1) + check(arr,j + 1,k);
            ans = max(ans,temp);
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp = vector<int>(n,-1);
        return check(arr,0,k);
    }
};
