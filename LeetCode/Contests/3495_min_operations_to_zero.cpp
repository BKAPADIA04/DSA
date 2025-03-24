#define ll long long
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        ll n = queries.size();
        ll prev = 1ll;
        ll ans = 0; 
        for(ll i = 0;i < n;i++) {
            ll count = 0;
            for(int j = 1;j < 17;j++) {
                ll prev = pow(4,j-1); ll curr = prev * 4ll;
                ll start = max((ll)queries[i][0],prev);
                ll end = min((ll)queries[i][1],curr-1);
                if(end >= start) count += (end - start + 1) * j;
                prev = curr;
            }
            ans += (count+1)/2;
        }
        return ans;
    }
};
