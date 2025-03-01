#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll n1 = nums1.size();
        ll sum1 = 0; ll zero1 = 0;
        for(ll i = 0;i < n1;i++) {
            if(nums1[i] != 0) sum1 += nums1[i];
            else {
                zero1++; sum1 += 1;
            }
        }

        ll n2 = nums2.size();
        ll sum2 = 0; ll zero2 = 0;
        for(ll i = 0;i < n2;i++) {
            if(nums2[i] != 0) sum2 += nums2[i];
            else {
                zero2++; sum2 += 1;
            }
        }
        if(sum1 > sum2 && zero2 == 0) return -1;
        if(sum2 > sum1 && zero1 == 0) return -1;
        return max(sum1,sum2);
    }
};
