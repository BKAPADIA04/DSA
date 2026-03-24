class Solution {
public:

    int n, target;
    vector<int>nums;
    int dp[41][100005];

    int check(int i, int xorr) {
        if(i == n) {
            if(xorr == target) return 0;
            return INT_MIN;
        }

        if(dp[i][xorr] != -1) return dp[i][xorr];
        
        int take = INT_MIN;
        int call = check(i+1, xorr^nums[i]);
        if(call != INT_MIN) {
            take = 1 + call;
        }
        int notTake = check(i + 1, xorr);

        return dp[i][xorr] = max(take, notTake);
    }
    
    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        this->nums = nums;
        this->target = target;

        memset(dp, -1, sizeof(dp));

        int ans = check(0,0);
        if(ans == INT_MIN) return -1;

        return n - ans;
    }
};
