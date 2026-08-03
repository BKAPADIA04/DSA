#define ll long long
class Solution {
public:

    vector<ll>preSum;
    ll n;

    ll solve(ll l, ll r) {
        if(l >= r) return 0ll;
        ll mid = (l + r)/2;
        ll cnt = solve(l, mid) + solve(mid+1,r);
        ll i = l; ll j = mid + 1;
        vector<ll>temp;
        while(i <= mid && j <= r) {
            if(preSum[i] < preSum[j]) {
                temp.push_back(preSum[i]);
                i++;
            }
            else {
                cnt += (mid - i + 1);
                temp.push_back(preSum[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(preSum[i]);
            i++;
        }

        while(j <= r) {
            temp.push_back(preSum[j]);
            j++;
        }

        for(ll k = 0;k < (ll)temp.size();k++) {
            preSum[l+k] = temp[k];
        }

        return cnt;
    }

    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        n = nums.size();
        preSum = vector<ll>(n+1);
        for(ll i = 1;i <= n;i++) {
            if(nums[i-1] % 2 == 0) preSum[i] = preSum[i-1] + b;
            else preSum[i] = preSum[i-1] - a;
        }
        ll ans = solve(0, n);
        return ans;
    }
};
