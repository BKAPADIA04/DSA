#define ll long long
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll>dp(n,0ll);
        unordered_map<ll,ll>mp;
        mp[0] = -1ll;
        ll preSum = 0ll;

        for(ll i = 0;i < n;i++) {
            preSum += (ll)nums[i];
            preSum %= (ll)k;

            dp[i] = (i > 0) ? dp[i-1] + (ll)nums[i] : (ll)nums[i];

            if(mp.find(preSum) != mp.end()) {
                if(preSum == 0ll && mp[0] == -1ll) dp[i] = min(dp[i], 0ll);
                else dp[i] = min(dp[i], dp[mp[preSum]]);
            }

            mp[preSum] = i;
        }

        return dp[n-1];
    }
};
