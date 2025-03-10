#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll>preSum(n+1,0);
        for(ll i = 1;i <= n;i++) {
            preSum[i] = preSum[i-1] + nums[i-1];
        }

        ll left = 1;
        ll right = 1;
        unordered_map<ll,ll>freq;
        ll maxi = 0ll;

        while(right <= n) {
            freq[nums[right-1]]++;

            if(right - left + 1 < k) {
                right++;
            }
            else {
                if(freq.size() == k) {
                    maxi = max(maxi,preSum[right] - preSum[left-1]);
                }
                freq[nums[left-1]]--;
                if(freq[nums[left-1]] == 0) freq.erase(nums[left-1]);
                left++;
                right++;
            }
        }
        return maxi;
    }
};
