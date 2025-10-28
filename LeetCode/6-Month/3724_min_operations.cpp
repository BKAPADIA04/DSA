#define ll long long
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        ll answer = 0ll;
        ll n = nums1.size();
        ll best = LLONG_MAX;

        for(ll i = 0;i < n;i++) {
            answer += abs(nums1[i] - nums2[i]);
            if(min(nums1[i],nums2[i]) <= nums2.back() && max(nums1[i],nums2[i]) >= nums2.back()) best = 1ll;
            best = min(best, 1ll + 1ll * min(abs(nums1[i] - nums2.back()), abs(nums2[i] - nums2.back())));
        }

        answer += best;

        return answer;
    }
};
