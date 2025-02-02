#define ll long long
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll n = nums.size();
        ll sum = accumulate(nums.begin(),nums.end(),0ll);
        ll curr_sum = 0;
        ll index = 0; ll diff = LLONG_MAX;
        for(ll i = 0;i < n;i++) {
            curr_sum += nums[i];
            sum -= nums[i];

            ll avg1 = curr_sum / (i+1);
            ll avg2 = 0;
            if(n - i - 1 != 0)
                avg2 = sum / (n - i - 1);

            if(abs(avg1 - avg2) < diff) {
                diff = abs(avg1 - avg2);
                index = i;
            }
        }
        return index;
    }
};