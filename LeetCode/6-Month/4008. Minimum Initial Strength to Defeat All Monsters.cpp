#define ll long long
class Solution {
public:
    
    map<ll,ll>umap;
    vector<ll>index, sweep;

    void printV(vector<ll>nums) {
        for(auto it : nums) {
            cout << it << " ";
        }
        cout << endl;
    }

    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        ll n = monsters.size();
        ll m = boosts.size();
        for(ll i = 0;i < m;i++) {
            ll l = boosts[i][0]; ll r = boosts[i][1]; ll v = boosts[i][2];
            umap[l] += v;
            umap[r+1] -= v;
        }
        ll sum = 0ll;
        for(auto it : umap) {
            sum += it.second;
            index.push_back(it.first);
            sweep.push_back(sum);
        }
        // printV(index);
        // printV(sweep);
        
        ll answer = 0ll;
        ll preSum = 0ll;
        for(ll i = 0;i < n;i++) {
            ll idx = upper_bound(index.begin(), index.end(), i) - index.begin() - 1;
            ll bonus = 0;
            if(idx >= 0) bonus = sweep[idx];
            if(monsters[i] > bonus) {
                ll tmp = preSum + monsters[i] - bonus;
                answer = max(answer, tmp);
            }
            preSum += monsters[i];
        }
        return answer;
    }
};
