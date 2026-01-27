#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        ll n = nums.size();
        // vector<ll>even(n,0);
        // vector<ll>odd(n,0);

        ll even = 0ll; ll odd = 0ll;

        if(nums[0] % 2 == 0) {
            even = nums[0];
            odd = nums[0] - (ll)x;
        }
        else {
            odd = nums[0];
            even = nums[0] - (ll)x;
        }

        for(ll i = 1;i < n;i++) {
            if(nums[i] % 2 == 0) {
                even = nums[i] + max(even, odd - (ll)x);
            }
            else {
                odd = nums[i] + max(odd, even - (ll)x);
            }
        }

        return max(even,odd);
    }
};
