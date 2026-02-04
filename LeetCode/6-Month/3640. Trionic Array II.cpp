#define ll long long
class Solution {
public:

    ll n;
    vector<int>nums;
    vector<vector<ll>>dp;

    ll check(ll i, ll trend) {
        if(i >= n) {
            if(trend == 3) return 0ll;
            return LLONG_MIN/2;
        }

        if(dp[i][trend] != -1ll) return dp[i][trend];

        ll take = LLONG_MIN/2;
        ll notTake = LLONG_MIN/2;

        if(trend == 0) {
            notTake = check(i + 1, 0);
        }

        if(trend == 3) {
            take = nums[i];
        }

        if(i+1 < n) {
            ll curr = nums[i];
            ll next = nums[i+1];

            if(trend == 0 && next > curr) {
                take = max(take, curr + check(i + 1,1));
            }

            if(trend == 1) {
                if(next > curr) {
                    take = max(take, curr + check(i + 1,1));
                }
                else if(next < curr) {
                    take = max(take, curr + check(i + 1,2));
                }
            }

            if(trend == 2) {
                if(next > curr) {
                    take = max(take, curr + check(i + 1,3));
                }
                else if(next < curr) {
                    take = max(take, curr + check(i + 1,2));
                }
            }

            if(trend == 3) {
                if(next > curr) {
                    take = max(take, curr + check(i + 1,3));
                }
            }
        }

        return dp[i][trend] = max(take, notTake);
    }

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        dp = vector<vector<ll>>(n,vector<ll>(4,-1ll));
        ll ans = check(0,0);

        return ans;
    }
};
