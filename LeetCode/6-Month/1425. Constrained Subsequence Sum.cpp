#define ll long long
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll>dp(n,0ll);
        for(ll i = 0;i < n;i++) dp[i] = (ll)nums[i];

        deque<ll>dq;
        dq.push_back(0ll);

        for(ll i = 1;i < n;i++) {
            while(!dq.empty() && dq.front() < (i - (ll)k)) dq.pop_front();
            dp[i] = max(dp[i], (ll)nums[i] + dp[dq.front()]);
            while(!dq.empty() && dp[i] > dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }

        ll maxi = dp[0];
        for(auto it:dp)  maxi = max(maxi, it);
        return maxi;
    }
};
