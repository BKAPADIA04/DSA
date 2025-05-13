#define ll long long
class Solution {
public:

    int minimumDifference(vector<int>& nums) {
        ll N = nums.size();
        ll n = N / 2;
        ll sum = accumulate(nums.begin(),nums.end(),0ll);
        vector<vector<ll>>left(n + 1), right(n + 1);
        for(ll i = 0;i < (1<<n);i++) {
            ll sz = 0; ll leftSum = 0ll; ll rightSum = 0ll;
            for(ll j = 0;j < n;j++) {
                if(i & (1 << j)) {
                    sz++;
                    leftSum += nums[j];
                    rightSum += nums[j+n];
                }
            }
            left[sz].push_back(leftSum);
            right[sz].push_back(rightSum);
        }

        for(ll sz = 0;sz <= n;sz++) {
            sort(right[sz].begin(),right[sz].end());
        }

        ll answer = INT_MAX;
        for(ll sz = 0;sz <= n;sz++) {
            for(ll i = 0;i < left[sz].size();i++) {
                ll a = left[sz][i];
                ll b = (sum - 2 * a)/2;
                auto it = lower_bound(right[n - sz].begin(),right[n - sz].end(),b);
                if(it != right[n - sz].end()) {
                    answer = min(answer, abs(sum - 2 * (a + *it)));
                }
                if(it != right[n - sz].begin()) {
                    it--;
                    answer = min(answer, abs(sum - 2 * (a + *it)));
                }
            }
        }
        return answer;
    }
};
