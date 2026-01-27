class Solution {
public:

    // Similar to LIS

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(1002,1));
        int ans = 1;

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < i;j++) {
                int diff = nums[j] - nums[i];
                dp[i][diff+500] = max(dp[i][diff+500], 1 + dp[j][diff+500]);
                ans = max(ans, dp[i][diff+500]);
            }
        }

        return ans;
    }
};
