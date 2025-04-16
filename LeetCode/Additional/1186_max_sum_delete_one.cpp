class Solution {
public:

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>left(n,0),right(n, 0);
        int sum = 0;
        for(int i = 0;i < n;i++) {
            sum = max(sum,0) + nums[i];
            left[i] = sum;
        }

        sum = 0;
        for(int i = n - 1;i >= 0;i--) {
            sum = max(sum,0) + nums[i];
            right[i] = sum;
        }

        int ans = *max_element(left.begin(),left.end());
        for(int i = 0;i < n;i++) {
            int leftSum = i > 0 ? left[i - 1] : 0;
            int rightSum = i < n - 1 ? right[i + 1] : 0;
            ans = max(ans, leftSum + rightSum);
        }
        return ans;
    }
};
