class Solution {
public:

    vector<vector<vector<int>>>dp;;
    int check(int i, int k, int last, int n, vector<int>& positions, vector<int>& times, vector<int>& preSum) {
        if(i == (n - 1)) {
            if(k == 0) return 0;
            return 1e9;
        }

        if(dp[i][k][last] != -1) return dp[i][k][last];

        int ans = INT_MAX;
        int rate = preSum[i] - (last > 0 ? preSum[last - 1] : 0);
        int till = min(n - 1, i + k + 1);  // You cannot exceed available k merges, so j - i - 1 <= k ⇒ j <= i + k + 1.
        for(int j = i + 1;j <= till;j++) {
            int dist = positions[j] - positions[i];
            int temp = dist * rate + check(j, k - (j - i - 1), i + 1, n, positions,times,preSum);
            ans = min(ans,temp);
        }
        return dp[i][k][last] = ans;
    }

    int minTravelTime(int l, int n, int k, vector<int>& positions, vector<int>& times) {
        vector<int>preSum(n,0);
        preSum[0] = times[0];
        for(int i = 1;i < n - 1;i++) {
            preSum[i] = preSum[i - 1] + times[i];
        }
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(k + 1,vector<int>(n + 1,-1)));
        return check(0,k,0,n,positions,times,preSum);
    }
};
