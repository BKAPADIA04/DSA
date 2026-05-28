class Solution {
public:
    int n;
    vector<int>nums;
    int k; int op1; int op2;
    vector<vector<vector<int>>>dp;    

    int check(int i, int op1, int op2) {
        if(op1 == 0 && op2 == 0) return 0;
        if(i == n) {
            return 0;
        }

        if(dp[i][op1][op2] != -1) return dp[i][op1][op2];

        int ans = check(i+1, op1, op2);
        if(op1 > 0) {
            ans = max(ans, nums[i]/2 + check(i+1, op1 - 1, op2));
        }

        if(op2 > 0 && nums[i] >= k) {
            ans = max(ans, k + check(i+1, op1, op2 - 1));
        }

        if(op1 > 0 && op2 > 0) {
            if(nums[i] >= k) {
                ans = max(ans, k + (nums[i] - k)/2 + check(i+1, op1 - 1, op2 - 1));
            }

            int newNo = (nums[i] + 1)/2;
            if(newNo >= k) {
                ans = max(ans, k + nums[i]/2 + check(i+1, op1 - 1, op2 - 1));
            }
        }
        return dp[i][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        this->nums = nums;
        this->k = k;
        this->op1 = op1;
        this->op2 = op2;

        sort(nums.rbegin(), nums.rend());
        n = nums.size();
        int summ = accumulate(nums.begin(), nums.end(), 0);

        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(op1+1, vector<int>(op2 + 1, -1)));
        return summ - check(0, op1, op2);
    }
};
