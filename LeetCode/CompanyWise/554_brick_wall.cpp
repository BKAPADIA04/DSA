#define ll long long
class Solution {
public:

    int leastBricks(vector<vector<int>>& wall) {
        ll n = wall.size();
        unordered_map<ll,ll>nums;
        for(ll i = 0;i < n;i++) {
            ll curr = 0;
            for(ll j = 0;j < wall[i].size() - 1;j++) {
                curr += wall[i][j];
                nums[curr]++;
            }
        }
        ll maxi = 0ll;
        for(auto it : nums) {
            maxi = max(maxi,it.second);
        }

        return n - maxi;
    }
};
