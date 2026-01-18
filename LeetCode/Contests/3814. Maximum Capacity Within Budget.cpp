#define ll long long
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<ll,ll>>nums;
        int n = costs.size();
        for(ll i = 0;i < n;i++) nums.push_back({costs[i], capacity[i]});
        sort(nums.begin(),nums.end());
        // sort(costs.begin(),costs.end());

        vector<ll>preMax(n, 0);
        for(ll i = 0;i < n;i++) {
            preMax[i] = max(nums[i].second, (i ? preMax[i-1] : 0));
        }

        ll ans = 0;
        for(ll i = 0;i < n;i++) {
            ll possiAns = nums[i].second;
            ll remCost = (ll)budget - nums[i].first;
            if(remCost <= 0) continue;
            ans = max(ans, possiAns);

            ll low = 0; ll high = i - 1;
            ll j = -1;

            while(low <= high) {
                ll mid = (low + high)/2;
                // cout << i << " " << mid << endl;
                if(nums[mid].first < remCost) {
                    j = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            if(j >= 0) {
                ans = max(ans, (ll)possiAns + preMax[j]);
            }
        }

        return ans;
    }
};
