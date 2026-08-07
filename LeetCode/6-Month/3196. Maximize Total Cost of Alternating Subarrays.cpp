#define ll long long
class Solution {
public:

    vector<int>nums;
    ll n;
    vector<vector<ll>>dp;

    ll check(ll idx, ll flag) {
        if(idx == n) return 0ll;

        if(dp[idx][flag] != LLONG_MIN) return dp[idx][flag];

        ll val = nums[idx];
        if(flag == 0) val = -nums[idx];

        ll opt1 = val + check(idx+1, 1 - flag);
        ll opt2 = val + check(idx+1, 1);

        return dp[idx][flag] = max(opt1, opt2);
    }

    long long maximumTotalCost(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        dp = vector<vector<ll>>(n,vector<ll>(2,LLONG_MIN));
        return check(0, 1);
    }
};
