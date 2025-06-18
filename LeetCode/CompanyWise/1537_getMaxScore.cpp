#define ll long long
class Solution {
public:

    ll mod = 1e9 + 7;

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        ll m = nums2.size();

        vector<ll>dp1(n+1,0); vector<ll>dp2(m+1,0);
        dp1[0] = dp2[0] = 0;
        ll i = 1; ll j = 1;
        while(i <= n && j <= m) {
            if(nums1[i-1] < nums2[j-1]) {
                dp1[i] = (dp1[i - 1] + (ll)nums1[i-1]);
                i++;
            }
            else if(nums1[i-1] > nums2[j-1]) {
                dp2[j] = (dp2[j - 1] + (ll)nums2[j-1]);
                j++;
            }
            else {
                dp1[i] = dp2[j] = (max(dp1[i - 1],dp2[j - 1]) + (ll)nums1[i-1]);
                dp1[i] %= mod;
                dp2[j] %= mod;
                i++;
                j++;
            }
        }

        while(i <= n) {
            dp1[i] = (dp1[i-1] + (ll)nums1[i-1]);
            i++;
        }
        while(j <= m) {
            dp2[j] = (dp2[j-1] + (ll)nums2[j-1]);
            j++;
        }

        return max(dp1[n],dp2[m]) % mod;
    }
};
