#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;

    int numOfSubarrays(vector<int>& nums) {
        ll n = nums.size();
        ll answer = 0ll;
        // set<ll>even_pre,odd_pre;
        ll even_pre = 1;// for zero
        ll odd_pre = 0;
        ll pre_sum = 0ll;

        for(ll i = 0;i < n;i++) {
            pre_sum += (ll)nums[i];

            if(pre_sum % 2 == 0) {
                answer += odd_pre % mod;
                even_pre++;
            }
            else {
                answer += even_pre % mod;
                odd_pre++;
            }
        }
        return answer % mod;
    }
};
