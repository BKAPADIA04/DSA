#define ll long long
class Solution {
public:

    ll n;
    vector<int> nums; vector<int> colors;
    vector<ll>dp;
    
    ll check(ll i) {
        if(i == n) return 0ll;

        if(dp[i] != -1ll) return dp[i];

        ll take = nums[i]; ll notTake = 0ll;

        if(i + 1 < n) {
            if(colors[i] != colors[i+1]) take = nums[i] + check(i+1);
            notTake = check(i+1);
        } 

        if(i + 2 < n) {
            take = max(take, nums[i] + check(i+2));
        }

        return dp[i] = max(take, notTake);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        n = nums.size();
        this->nums = nums;
        this->colors = colors;
        dp = vector<ll>(n,-1ll);
        return check(0);
    }
};
