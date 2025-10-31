#define ll long long
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<ll,ll>freqMap;
        for(auto it : power) freqMap[it]++;
        vector<pair<ll,ll>>nums;
        for(auto it : freqMap) nums.push_back({it.first,it.second});

        ll n = nums.size();
        ll answer = 0ll;
        vector<ll>dp(n,0);
        for(ll i = 0,j = 0;i < n;i++) {
            while(j < i && nums[j].first < nums[i].first - 2) {
                answer = max(answer, dp[j]);
                j++;
            }
            dp[i] = answer + 1ll * nums[i].first * nums[i].second;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
