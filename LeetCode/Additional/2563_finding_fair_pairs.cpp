#define ll long long
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        ll ans = 0ll;
        for(int i = 0;i < n;i++) {
            int findL = lower - 1 - nums[i];
            int findU = upper - nums[i];
            ll lowerCount = upper_bound(nums.begin() + i + 1,nums.end(),findL) - nums.begin() - 1;
            ll upperCount = upper_bound(nums.begin() + i + 1,nums.end(),findU) - nums.begin() - 1;

            lowerCount = lowerCount - i;
            upperCount = upperCount - i;

            ans += (upperCount - lowerCount);
        }
        return ans;
    }
};
