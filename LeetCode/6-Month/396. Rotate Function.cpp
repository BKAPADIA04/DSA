class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i < n;i++) {
            ans += i * nums[i];
        }

        int maxi = ans;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int i = n - 1;i > 0;i--) {
            ans = ans + sum - n * nums[i];
            maxi = max(maxi, ans);
        }

        return maxi;
    }
};
