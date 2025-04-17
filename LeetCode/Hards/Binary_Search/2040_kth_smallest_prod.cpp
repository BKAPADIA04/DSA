#define ll long long
class Solution {
public:

    bool check(vector<int>& nums1, vector<int>& nums2, ll k, ll mid) {
        ll n1 = nums1.size(); ll n2 = nums2.size();
        ll count = 0;
        for(ll i = 0;i < n1;i++) {
            if(nums1[i] > 0) {
                ll temp = floor(mid / (nums1[i] * 1.0));
                ll upperBound = upper_bound(nums2.begin(),nums2.end(),temp) - nums2.begin();
                count += upperBound;
            }
            else if(nums1[i] < 0) {
                ll temp = ceil(mid / (nums1[i] * 1.0));
                ll lowerBound = lower_bound(nums2.begin(),nums2.end(),temp) - nums2.begin();
                count += (n2 - lowerBound);
            }
            else {
                if(mid >= 0) count += n2;
            }
        }
        return count >= k;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll low = -1e10; ll high = 1e10;
        ll ans = 0;
        while(low <= high) {
            ll mid = low + (high - low)/2;
            if(check(nums1,nums2,k,mid)) {
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
