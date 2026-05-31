#define ll long long
class Solution {
public:
    
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();

        int mini=INT_MAX;
        for(int i=0;i<n;i++)mini=min(mini,items[i][1]);

        vector<ll>cnt(n+1,0);
        for(int i=0;i<n;i++) cnt[items[i][0]]++;

        vector<ll>mul(n+1,0);
        for(int i = 1;i <= n;i++) {
            for(int j = i;j <= n;j += i) {
                mul[i] += cnt[j];
            }
        }

        map<int,ll>mp;
        for(int i = 0;i < items.size();i++) {
            int fact = items[i][0]; int price = items[i][1];
            ll d = mul[fact] - 1;
            if(d > 0 && price <= 2 * mini) mp[price] += d;
        }

        ll ans = 0ll;
        for(auto it : mp) {
            ll price = it.first;
            ll quan = it.second;

            ll pick = min(quan, budget/price);
            ans += 2 * pick;
            budget -= pick * price;
            if(budget <= 0) break;
        }

        ans += budget / mini;

        return ans;
    }
};
