#define ll long long
class Solution {
public:

    vector<ll>preSum;
    vector<vector<ll>>dp;
    vector<int>result;

    ll check(ll index, ll count, ll k, ll n) {
        if(index == n) {
            if(count == 0) return 0ll;
            return LLONG_MIN;
        }

        if(dp[index][count] != -1) return dp[index][count];
        
        ll opt1 = check(index + 1, count, k, n);
        ll opt2 = 0ll;
        if(index + k <= n && count > 0) {
            ll next = check(index + k, count - 1, k, n);
            if (next != LLONG_MIN)
                opt2 = preSum[index + k] - preSum[index] + next;
        }

        return dp[index][count] = max(opt1,opt2);
    }

    void extract(ll index, ll count, ll k, ll n) {
        while(count > 0 && index < n) {
            ll opt1 = check(index + 1, count, k, n);
            ll opt2 = LLONG_MIN;
            if(index + k <= n) {
                ll next = check(index + k, count - 1, k, n);
                if (next != LLONG_MIN)
                    opt2 = preSum[index + k] - preSum[index] + next;
            }

            if(opt2 >= opt1) {
                result.push_back((int)index);
                index += k;
                count--;
            } else {
                index++;
            }
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        ll n = nums.size();
        preSum = vector<ll>(n + 1,0);
        for(ll i = 1;i <= n;i++) preSum[i] = preSum[i-1] + (ll)nums[i-1];
        dp = vector<vector<ll>>(n,vector<ll>(4,-1));
         
        extract(0,3,k,n);
        return result;
    }
};
