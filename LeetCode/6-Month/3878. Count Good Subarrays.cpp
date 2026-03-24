#define ll long long
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,0); 
        vector<int>right(n, n - 1);
        vector<int>prev(31,-1), next(31, n);

        for(int i = 0;i < n;i++) {
            for(int bit = 0;bit < 31;bit++) {
                if((nums[i] & (1 << bit)) == 0) {
                    left[i] = max(left[i], prev[bit] + 1);
                }
                else {
                    prev[bit] = i;
                }
            }
        }

        for(int i = n - 1;i >= 0;i--) {
            for(int bit = 0;bit < 31;bit++) {
                if((nums[i] & (1 << bit)) == 0) {
                    right[i] = min(right[i], next[bit] - 1);
                }
                else {
                    next[bit] = i;
                }
            }
        }

        ll answer = 0ll;
        unordered_map<ll,ll>lastOcc;
        for(int i = 0;i < n;i++) {
            ll l = left[i]; ll r = right[i];
            if(lastOcc.find(nums[i]) != lastOcc.end()) {
                l = max(l, lastOcc[nums[i]] + 1);
            }
            lastOcc[nums[i]] = i;

            answer += (ll)(i - l + 1) * (ll)(r - i + 1);
        }

        return answer;
    }
};
