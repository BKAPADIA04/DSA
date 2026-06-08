#define ll long long
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        ll n = nums.size();
        unordered_map<ll,ll>mp;
        mp[0] = 1;
        ll preXor = 0ll;
        ll answer = 0ll;
        for(ll i = 0;i < n;i++) {
            preXor ^= nums[i];
            answer += mp[preXor];
            mp[preXor]++;
        }

        return answer;
    }
};
