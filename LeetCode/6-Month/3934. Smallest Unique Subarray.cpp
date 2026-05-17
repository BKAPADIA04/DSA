#define ll long long
class Solution {
public:

    ll check(vector<int>&nums, ll mid) {
        ll n = nums.size();
        ll sum = 0ll;
        ll curr = 0ll;
        unordered_map<ll,ll>freq;
        for(ll i = 0;i < mid;i++) {
            sum += nums[i];
            curr += nums[i] * (mid - i);
        }

        freq[curr]++;

        for(ll i = mid;i < n;i++) {
            sum -= nums[i-mid];
            curr -= nums[i-mid] * mid;

            curr = curr + sum + nums[i];
            sum += nums[i];

            // if(freq.find(curr) != freq.end()) return false;
            freq[curr]++;
        }

        for(auto it : freq) if(it.second == 1) return true;


        return false;
    }
    
    int smallestUniqueSubarray(vector<int>& nums) {
        ll n = nums.size();
        ll low = 1; ll high = n;
        ll ans = n;
        // for(ll i = 1;i <= n;i++) {
        //     if(check(nums, i)) return i;
        // }
        while(low <= high) {
            ll mid = (low + high)/2;
            if(check(nums, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
