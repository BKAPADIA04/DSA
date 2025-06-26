#define ll long long
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        ll n = nums.size();
        unordered_map<ll,ll>preSum;
        preSum[0] = -1;

        ll ans = INT_MAX;
        ll sum = 0ll;
        for(ll i = 0;i < n;i++) {
            sum += nums[i];
            ll req = sum - target;
            if(preSum.find(req) != preSum.end()) {
                ans = min(ans, i - preSum[req]);
            }
            preSum[sum] = i;
        }

        ll total = sum;
        sum = 0ll;
        for(ll i = n - 1;i >= 0;i--) {
            sum += nums[i];
            ll req = target - sum;
            ll count = n - i;
            count += n * floor(req/total);
            req %= total;
            if(preSum.find(req) != preSum.end()) {
                ans = min(ans, count + preSum[req] + 1);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
