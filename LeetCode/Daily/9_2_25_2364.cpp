#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll n = nums.size();
        ll totalPairs = (n * (n-1))/2;
        unordered_map<ll,ll>m;
        m[nums[0] - 0]++;

        ll count = 0;
        for(ll i = 1;i < n;i++) {
            ll check = nums[i] - i;
            if(m.find(check) != m.end()) {
                count += m[check];
            }
            m[check]++;
        }
        return totalPairs - count;
    }
};
