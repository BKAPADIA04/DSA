class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int>dp;

        int ans = 1;
        for(int i = 0;i < n;i++) {
            int num1 = 1; int num2 = 1;
            if(dp.find(nums[i] - 1) != dp.end()) {
                num1 = 1 + dp[nums[i] - 1];
            }

            if(dp.find(nums[i]) != dp.end()) {
                num2 = 1 + dp[nums[i]];
            }


            if(dp.find(nums[i]) == dp.end()) {
                dp[nums[i]] = num1;
            }
            else {
                dp[nums[i]] = max(dp[nums[i]], num1);
            }

            if(dp.find(nums[i] + 1) == dp.end()) {
                dp[nums[i] + 1] = num2;
            }
            else {
                dp[nums[i] + 1] = max(dp[nums[i] + 1], num2);
            }

            cout << i << " " << dp[nums[i]] << " " << dp[nums[i] + 1] << endl;

            ans = max({ans, dp[nums[i]], dp[nums[i] + 1]});
        } 

        return ans;
    }
};
