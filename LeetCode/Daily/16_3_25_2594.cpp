#define ll long long

class Solution {
public:

    bool check(vector<int>&ranks,int cars,ll mid) {
        ll n = ranks.size(); ll count = 0ll;
        for(ll i = 0;i < n;i++) {
            count += sqrt(mid/ranks[i]);
        }
        return count >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll n = ranks.size();
        ll low = 0ll; ll high = LLONG_MAX; ll ans = -1ll;
        while(low <= high) {
            ll mid = (low + high)/2;
            if(check(ranks,cars,mid)) {
                ans = mid;
                high = mid - 1;
            }   
            else low = mid + 1;
        }
        return ans;
    }
};
