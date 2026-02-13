class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0;i < n;i++) {
            if(nums[i] == i) continue;
            ans &= nums[i];
        }

        if(ans == INT_MAX) return 0;
        return ans;
    }
};
