#define ll long long
class Solution {
public:

    ll n;
    vector<int>nums;
    ll dp[100001][2];

    ll check(ll i, ll skip) {
        if(i >= n - 1) return 0ll;
        if(dp[i][skip] != -1) return dp[i][skip];

        ll ans = max(0, max(nums[i-1], nums[i+1]) + 1 - nums[i]);
        if(skip == 1) {
            return dp[i][skip] = ans + check(i+2, 1);
        }

        ll ans1 = ans + check(i+2,0);
        ll ans2 = ans + check(i+3,1);

        return dp[i][skip] = min(ans1, ans2);
    }

    long long minIncrease(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        ll ans = 0;
        if(n & 1) {
            for(int i = 1;i < n - 1;i += 2) {
                ans += max(0, max(nums[i-1], nums[i+1]) + 1 - nums[i]);
            }
            return ans;
        }
        
        memset(dp, -1, sizeof(dp));
        ans = min(check(1,0), check(2,1));

        return ans;
    }
};
