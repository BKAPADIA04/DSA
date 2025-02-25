#define ll long long
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        ll n = nums.size(); ll ans = 0;
        ll left = 0;
        while(left + 1 < n && nums[left] < nums[left+1]) left++;
        ll right = n - 1;
        while(right - 1 >= 0 && nums[right-1] < nums[right]) right--;

        ans += (n - right + 1);

        for(ll i = 0;i <= left;i++) {
            ll check = upper_bound(nums.begin() + right,nums.end(),nums[i]) - nums.begin();
            ans += (n - check + 1);
        }
        if(left == (n-1)) return (n*(n+1)/2);
        return ans;
    }
};
