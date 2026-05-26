#define ll long long
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        ll n = damage.size();
        vector<ll>prefix;
        prefix.push_back(0);
        for(auto it : damage) {
            ll temp = prefix.back() + it;
            prefix.push_back(temp);
        }

        ll ans = 0ll;
        for(ll i = 0;i < n;i++) {
            ll target = prefix[i+1] + requirement[i] - hp;
            ll lowerIndex = lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
            if(lowerIndex <= i) ans += i - lowerIndex + 1;
        }

        return ans;
    }
};
