#define ll long long
class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        sort(coords.begin(),coords.end());
        map<ll,vector<ll>>X,Y;

        int miniH = INT_MAX; int maxiH = INT_MIN;
        int miniV = INT_MAX; int maxiV = INT_MIN;

        for(auto it : coords) {
            int x = it[0]; int y = it[1];
            miniH = min(miniH,x);
            maxiH = max(maxiH,x);

            miniV = min(miniV,y);
            maxiV = max(maxiV,y);

            X[x].push_back(y);
            Y[y].push_back(x);
        }

        ll ans = -1ll;
        for(auto it : X) {
            if(it.second.size() == 1) continue;
            ll small = it.second[0];
            ll big = it.second[it.second.size() - 1];
            ll maxH = max(abs(miniH - it.first),abs(maxiH - it.first));
            if(maxH == 0) continue;
            ans = max(ans,(big - small) * maxH);
        }

        for(auto it : Y) {
            if(it.second.size() == 1) continue;
            ll small = it.second[0];
            ll big = it.second[it.second.size() - 1];
            ll maxH = max(abs(miniV - it.first),abs(maxiV - it.first));
            if(maxH == 0) continue;
            ans = max(ans,(big - small) * maxH);
        }
        
        return ans;
    }
};
