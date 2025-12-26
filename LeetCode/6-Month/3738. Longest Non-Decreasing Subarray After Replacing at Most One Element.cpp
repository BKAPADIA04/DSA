class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        
        vector<int> left(n, 1), right(n, 1);

        // left[i] = length of non-decreasing subarray ending at i
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] <= nums[i])
                left[i] = left[i - 1] + 1;
        }

        // right[i] = length of non-decreasing subarray starting at i
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int ans = 1;
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                ans = max(ans, right[j + 1] + 1);
            } else if (j == n - 1) {
                ans = max(ans, left[j - 1] + 1);
            } else if (nums[j - 1] <= nums[j + 1]) {
                ans = max(ans, left[j - 1] + right[j + 1] + 1);
            } else {
                ans = max(ans, max(left[j - 1], right[j + 1]) + 1);
            }
        }

        return ans;
    }
};
