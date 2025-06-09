#define ll long long
class Solution {
public:

    int n;
    vector<int>nums;
    vector<vector<vector<vector<ll>>>>dp;
    
    ll check(int index, int buy, int sold, int k) {
        if(index == n) {
            if(sold == 1) return INT_MIN;
            return 0;
        }
        if(k == 0) return 0;

        if(dp[index][buy][sold][k] != -1) return dp[index][buy][sold][k];
        ll ans = 0ll;

        if(buy == 0 && sold == 0) {
            ll opt1 = -nums[index] + check(index + 1,1,0,k);
            ll opt2 = nums[index] + check(index + 1,0,1,k);
            ll opt3 = check(index + 1,0,0,k);
            ans = max(opt3,max(opt1,opt2));
        }
        if(buy == 1 && sold == 0) {
            ll opt1 = nums[index] + check(index + 1,0,0,k-1);
            ll opt2 = check(index + 1,1,0,k);
            ans = max(opt1,opt2);
        }
        if(buy == 0 && sold == 1) {
            ll opt1 = -nums[index] + check(index + 1,0,0,k-1);
            ll opt2 = check(index + 1,0,1,k);
            ans = max(opt1,opt2);
        }
        
    return dp[index][buy][sold][k] = ans;
        
    }
    
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        nums = prices;
        dp = vector<vector<vector<vector<ll>>>>(n,vector<vector<vector<ll>>>(2,vector<vector<ll>>(2,vector<ll>(k+1,-1))));
        return check(0,0,0,k);
    }
};
