class Solution {
public:

    int n;
    vector<int>nums;
    vector<vector<int>> dp;

    int check(int i, int k, int end) {
        if(k == 0) return 0;
        if(i > end) {
            return INT_MAX;
        }

        if(dp[i][k] != -1) return dp[i][k];

        int left = nums[(i - 1 + n) % n];
        int right = nums[(i + 1) % n];

        int ops = 0;
        
        if (nums[i] <= left || nums[i] <= right) {
            ops = max(left, right) - nums[i] + 1LL;
        }
        int temp = check(i + 2, k - 1, end); 
        int pick = INT_MAX;
        if(temp != INT_MAX) {
            pick = ops + temp;
        }
        
        int skip = check(i + 1, k, end);

        return dp[i][k] = min(pick, skip);
    }

    int minOperations(vector<int>& nums, int k) {
        n = nums.size();
        if (n / 2 < k) return -1;
        this->nums = nums;
        dp.assign(n, vector<int>(k + 1, -1));
        int ans1 = check(0, k, n - 2);
        dp.assign(n, vector<int>(k + 1, -1));
        int ans2 = check(1, k, n - 1);

        int ans = min(ans1, ans2);
        if(ans >= INT_MAX) return -1;
        return ans;
    }
};
