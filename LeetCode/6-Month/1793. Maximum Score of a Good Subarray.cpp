class Solution {
public:

    int check(vector<int>&nums, int k) {
        int n = nums.size();
        vector<int> left(k, 0);
        int currMin = INT_MAX;
        for (int i = k - 1; i >= 0; i--) {
            currMin = min(currMin, nums[i]);
            left[i] = currMin;
        }
        
        vector<int> right;
        currMin = INT_MAX;
        for (int i = k; i < n; i++) {
            currMin = min(currMin, nums[i]);
            right.push_back(currMin);
        }

        int ans = 0;
        for (int j = 0; j < right.size(); j++) {
            currMin = right[j];
            int i = lower_bound(left.begin(), left.end(), currMin) - left.begin();
            int size = (k + j) - i + 1;
            ans = max(ans, currMin * size);
        }
        
        return ans;
    }

    int maximumScore(vector<int>& nums, int k) {
        int ans = check(nums, k);
        reverse(nums.begin(), nums.end());
        return max(ans, check(nums, nums.size() - k - 1));
    }
};
