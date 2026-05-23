#define ll long long
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        ll sum = accumulate(machines.begin(), machines.end(), 0ll);
        ll n = machines.size();

        if(sum % n) return -1;
        ll target = sum/n;

        ll ans = 0ll; ll prefix = 0ll;

        for(ll i = 0;i < n;i++) {   
            ll diff = machines[i] - target;
            prefix += diff;
            ans = max(ans, max(abs(prefix), diff));
        }

        return ans;
    }
};
