class Solution {
public:

    int n;
    int mod = 1e9 + 7;
    vector<int>nums;
    vector<vector<int>>dp;

    int check(int i, int ones) {
        if(i == n) {
            if(ones == 1) return 1;
            return 0;
        }


        if(nums[i] == 1) ones++;
        if(ones > 1) return 0;

        if(dp[i][ones] != -1) return dp[i][ones];
        
        // same subarray
        int pick = check(i+1, ones) % mod;
        int notpick = 0; // break subarray
        if(ones == 1) {
            notpick = check(i+1, 0) % mod;
        }

        return dp[i][ones] = (pick + notpick) % mod;
    }

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        dp = vector<vector<int>>(n, vector<int>(2,-1));
        return check(0, 0);
    }
};
