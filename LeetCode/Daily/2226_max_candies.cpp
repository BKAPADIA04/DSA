#define ll long long
class Solution {
public:

    bool check(vector<int>&candies,ll mid,ll k) {
        ll n = candies.size();
        ll count = 0ll;
        for(ll i = 0;i < n;i++) {
            count += (candies[i]/mid);
            if(count >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        ll n = candies.size();
        ll low = 0; ll high = LLONG_MAX; ll answer = 0ll;
        while(low <= high) {
            ll mid = (low + high)/2;
            if(mid == 0) return 0;
            if(check(candies,mid,k)) {
                answer = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return answer;
    }
};
