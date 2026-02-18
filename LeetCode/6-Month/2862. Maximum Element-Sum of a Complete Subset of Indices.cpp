#define ll long long
class Solution {
public:
    
    pair<ll,ll> check(ll n) {
        if(n == 2) return {2,0};
        ll ans = 0ll; ll flag = 0ll;ll cnt;
        for(ll i = 2;i * i <= n;i++) {
            if(i != 2 && (i & 1) == 0) continue;
            ll cnt = 0ll;
            while((n % i) == 0) {
                n /= i;
                cnt++;
                flag = 1ll;
            }
            if(cnt & 1) {
                if(ans == 0ll) ans = 1ll;
                ans = ans * i;
            }
        }
        if(n != 1) {
            cnt++;
            if(ans == 0ll) ans = 1ll;
            ans = ans * n;
        }
        return {ans,flag};
    }

    long long maximumSum(vector<int>& nums) {
        ll n = nums.size();
        unordered_map<ll,ll>mp;
        ll maxi = 0ll;
        for(ll i = 0;i < n;i++) {
            pair<ll,ll> call = check(i+1);
            if(i != 0 && call.second == 0ll) call.first = i + 1;
            
            mp[call.first] += (ll)nums[i];
            maxi = max(maxi, mp[call.first]);
        }

        return maxi;
    }
};
