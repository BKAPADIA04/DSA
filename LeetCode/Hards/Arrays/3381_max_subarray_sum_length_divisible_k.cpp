#define ll long long
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        unordered_map<ll,ll>minPreSum;
        // minPreSum[0] = 0;
        minPreSum[-1] = 0;
        ll n = nums.size(); ll ans = LLONG_MIN;
        ll curr_sum = 0ll;
        for(ll i = 0;i < k;i++) {
            curr_sum += nums[i];
            // if(minPreSum.count(i % k)) minPreSum[i % k] = min(minPreSum[i % k], curr_sum);
            minPreSum[i % k] = curr_sum;
        }
        cout << curr_sum << endl;
        ans = max(ans,curr_sum - minPreSum[-1]);
        for(ll i = k;i < n;i++) {
            curr_sum += nums[i];
            if((i+1)% k == 0) {
                ans = max(ans,curr_sum - minPreSum[-1]);
            }
            ans = max(ans,curr_sum - minPreSum[i % k]);
            minPreSum[i % k] = min(minPreSum[i % k], curr_sum);
        }
        return ans;
    }
};
