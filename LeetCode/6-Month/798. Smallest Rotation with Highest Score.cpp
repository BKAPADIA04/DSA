#define ll long long
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        ll n = nums.size();
        vector<ll>sweep(n + 1);

        for(ll i = 0;i < n;i++) {
            ll left = (i + 1) % n;
            ll right = (n + i + 1 - nums[i]) % n;

            if(left <= right) {
                sweep[left]++;
                sweep[right]--;
            }
            else {
                sweep[left]++;
                sweep[n]--;
                sweep[0]++;
                sweep[right]--;
            }
        }

        ll maxScore = -1ll;
        int minK = -1;

        ll preSum = 0ll;
        for(ll i = 0;i < n;i++) {
            preSum += sweep[i];
            if(preSum > maxScore) {
                maxScore = preSum;
                minK = i;
            }
        }
        return minK;
    }
};
